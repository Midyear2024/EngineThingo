#include "MovementComponent.h"
#include "Transform.h"


MovementComponent::MovementComponent(GameObject& gameObject, float movementSpeed) : movementSpeed{movementSpeed}
{
    gameObject.AddComponent(this);
    this->AddGameObjectReference(gameObject);
}

void MovementComponent::Move(const float dt)
{
}

void MovementComponent::Update(float dt)
{
    Move(dt);
}
