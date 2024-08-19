#pragma once
#include "MovementComponent.h"
class ProjectileMovement :
    public MovementComponent
{
public:
    ProjectileMovement(GameObject& gameObject, float movementSpeed);

protected:
    virtual void Move(const float dt) override;
};

