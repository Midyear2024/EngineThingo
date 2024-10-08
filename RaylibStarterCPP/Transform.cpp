#include "Transform.h"
#include "glm/ext.hpp"

void MyTransform::CalculateWorldTransform()
{
    if (parentObject) {
        worldTransform = parentObject->GetWorldTransform() * localTransform;
        worldScale = localScale;
    }
    else {
        worldTransform = localTransform;
        worldScale = localScale;
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

}

glm::vec3 MyTransform::GetLocalPosition() const
{
    return glm::vec3(localTransform[3][0], localTransform[3][1], localTransform[3][2]);
}

glm::vec3 MyTransform::GetLocalForward() const
{
    return glm::vec3(localTransform[1][0], localTransform[1][1], localTransform[1][2]);
}

glm::vec3 MyTransform::GetLocalUp() const
{
    return glm::vec3(localTransform[2][0], localTransform[2][1], localTransform[2][2]);
}


glm::vec3 MyTransform::GetLocalRight() const
{
   return glm::vec3(localTransform[0][0], localTransform[0][1], 0);
}

glm::vec3 MyTransform::GetWorldPosition()
{

    CalculateWorldTransform();
  
    
    return glm::vec3(worldTransform[3][0], worldTransform[3][1], worldTransform[3][2]);
}

glm::vec3 MyTransform::GetWorldRight()
{

    CalculateWorldTransform();

    
    return glm::vec3(worldTransform[0][0], worldTransform[0][1], 0);
}

glm::vec3 MyTransform::GetWorldForward() 
{

    CalculateWorldTransform();

    return glm::vec3(worldTransform[1][0], worldTransform[1][1], worldTransform[1][2]);
}

glm::vec3 MyTransform::GetWorldUp()
{
    CalculateWorldTransform();
    return glm::vec3(worldTransform[2][0], worldTransform[2][1], worldTransform[2][2]);
}


glm::mat4 MyTransform::GetWorldTransform() 
{

    CalculateWorldTransform();

    return worldTransform;
}

glm::mat4 MyTransform::GetLocalTransform() const
{
    return localTransform;
}

float MyTransform::GetLocalScaleX() const
{
    return localScale.x;
}

float MyTransform::GetWorldScaleX()
{

    CalculateWorldTransform();

    return worldScale.x;
}

float MyTransform::GetLocalScaleY() const
{
    return localScale.y;
}

float MyTransform::GetWorldScaleY()
{

    CalculateWorldTransform();

    
    return worldScale.y;
}

float MyTransform::GetLocalScaleZ() const
{
    return localScale.z;
}

float MyTransform::GetWorldScaleZ()
{

    CalculateWorldTransform();

    return worldScale.z;
}

glm::vec3 MyTransform::GetWorldScale()
{
    
    return worldScale;
    
}

glm::vec3 MyTransform::GetLocalScale() const
{
    return localScale;
}

void MyTransform::AddParent(MyTransform* parent)
{
    parentObject = parent;
    CalculateWorldTransform();
}



void MyTransform::Translate(glm::vec3 translateVector)
{
    auto temp = glm::translate(localTransform, translateVector);
    localTransform = glm::translate(localTransform, translateVector);

    
}

void MyTransform::Rotate(float radians, glm::vec3 axis)
{
    localTransform = glm::rotate(localTransform, radians, glm::vec3{ 0,0,1 });
}



void MyTransform::Scale(glm::vec3 scale)
{
    localScale = scale;

}

void MyTransform::SetPosition(glm::vec3 newPosition)
{

    localTransform[3][0] = newPosition.x;
    localTransform[3][1] = newPosition.y;
    localTransform[3][2] = newPosition.z;

}




