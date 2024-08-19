#pragma once
#include "RotationComponent.h"
class TurretRotation :
    public RotationComponent
{

public:
    TurretRotation(GameObject& gameObject, float startingRotation, float rotationSpeed);

protected:
    virtual void Rotate(float dt) override;
};


