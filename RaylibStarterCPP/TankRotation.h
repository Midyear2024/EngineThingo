#pragma once
#include "RotationComponent.h"
class TankRotation :
    public RotationComponent
{
public:
    TankRotation(GameObject& gameObject, float startingRotation, float rotationSpeed);

protected:
    virtual void Rotate(float dt) override;
};

