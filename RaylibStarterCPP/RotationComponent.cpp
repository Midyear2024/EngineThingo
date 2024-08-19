#include "RotationComponent.h"
#include "Transform.h"

RotationComponent::RotationComponent(GameObject& gameObject, float startingRotation, float rotationSpeed) : currentRotation{startingRotation}, rotationSpeed{rotationSpeed}
{
	gameObject.AddComponent(this);
	this->AddGameObjectReference(gameObject);
}

void RotationComponent::Rotate(float dt)
{

}

void RotationComponent::Update(float dt)
{
	Rotate(dt);
}
