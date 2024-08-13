#include "Transform.h"
#include "glm/ext.hpp"

void MyTransform::CalculateWorldTransform()
{
    if (parentObject) {
        worldTransform = parentObject->GetWorldTransform() * localTransform;
    }
    else {
        worldTransform = localTransform;
    }
}

MyTransform::MyTransform() : MyTransform(glm::vec3(0))
{
    
}

MyTransform::MyTransform(glm::vec3 pos)
{
    localTransform = glm::mat4(1.0f);
    Translate(pos);

    parentObject = nullptr;
    CalculateWorldTransform();
    dirty = false;
}

MyTransform::MyTransform(glm::vec3 pos, float angle) : MyTransform(pos, angle, glm::vec3{1,1,1})
{

}

MyTransform::MyTransform(glm::vec3 pos, float angle, glm::vec3 scale)
{
    localTransform = glm::mat4(1.0f);
    Translate(pos);
    Rotate(angle);
    Scale(scale);

    CalculateWorldTransform();
    dirty = false;
}

glm::vec3 MyTransform::GetLocalPosition() const
{
    return glm::vec3(localTransform[3][0], localTransform[3][1], localTransform[3][2]);
}

glm::vec3 MyTransform::GetLocalForward() const
{
    return glm::normalize(glm::vec3(localTransform[1][0], localTransform[1][1], localTransform[1][2]));
}


glm::vec3 MyTransform::GetLocalRight() const
{
   return glm::normalize(glm::vec3(localTransform[0][0], localTransform[0][1], 0));
}

glm::vec3 MyTransform::GetWorldPosition()
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return glm::vec3(worldTransform[3][0], worldTransform[3][1], worldTransform[3][2]);
}

glm::vec3 MyTransform::GetWorldRight()
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return glm::normalize(glm::vec3(worldTransform[0][0], worldTransform[0][1], 0));
}

glm::vec3 MyTransform::GetWorldForward() 
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return glm::normalize(glm::vec3(worldTransform[1][0], worldTransform[1][1], worldTransform[1][2]));
}


glm::mat4 MyTransform::GetWorldTransform() 
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return worldTransform;
}

glm::mat4 MyTransform::GetLocalTransform() const
{
    return localTransform;
}

float MyTransform::GetLocalScaleX() const
{
    return glm::sqrt(localTransform[0][0] * localTransform[0][0] + localTransform[0][1] * localTransform[0][1] + localTransform[0][2] * localTransform[0][2]);
}

float MyTransform::GetWorldScaleX()
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return glm::sqrt(worldTransform[0][0] * worldTransform[0][0] + worldTransform[0][1] * worldTransform[0][1] + worldTransform[0][2] * worldTransform[0][2]);
}

float MyTransform::GetLocalScaleY() const
{
   return glm::sqrt(localTransform[1][0] * localTransform[1][0] + localTransform[1][1] * localTransform[1][1] + localTransform[1][2] * localTransform[1][2]);
}

float MyTransform::GetWorldScaleY()
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return glm::sqrt(worldTransform[1][0] * worldTransform[1][0] + worldTransform[1][1] * worldTransform[1][1] + worldTransform[1][2] * worldTransform[1][2]);
}

float MyTransform::GetLocalScaleZ() const
{
    return glm::sqrt(localTransform[2][0] * localTransform[2][0] + localTransform[2][1] * localTransform[2][1] + localTransform[2][2] * localTransform[2][2]);
}

float MyTransform::GetWorldScaleZ()
{
    if (dirty) {
        CalculateWorldTransform();
        dirty = false;
    }
    return glm::sqrt(worldTransform[2][0] * worldTransform[2][0] + worldTransform[2][1] * worldTransform[2][1] + worldTransform[2][2] * worldTransform[2][2]);
}

glm::vec3 MyTransform::GetWorldScale()
{
    
    return glm::vec3{ GetWorldScaleX(), GetWorldScaleY(), GetWorldScaleZ() };
    
}

glm::vec3 MyTransform::GetLocalScale() const
{
    return glm::vec3{ GetLocalScaleX(), GetLocalScaleY(), GetLocalScaleZ() };
}

void MyTransform::AddParent(MyTransform* parent)
{
    parentObject = parent;
    CalculateWorldTransform();
}



void MyTransform::Translate(glm::vec3 translateVector)
{
    localTransform = glm::translate(localTransform, translateVector);
    dirty = true;
    
}

void MyTransform::Rotate(float radians, glm::vec3 axis)
{
    localTransform = glm::rotate(localTransform, radians, glm::vec3{ localTransform[2] });
    dirty = true;
}

void MyTransform::Scale(glm::vec3 scale)
{
    localTransform  = glm::scale(localTransform, scale);
    dirty = true;
}


