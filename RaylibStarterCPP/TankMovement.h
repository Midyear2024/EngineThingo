#pragma once
#include "MovementComponent.h"
class TankMovement :
    public MovementComponent
{

public:
    TankMovement(GameObject& gameObject, float movementSpeed);
protected:
    virtual void Move(const float dt) override;
};

