#pragma once
#include "Component.h"
class RotationComponent :
    public Component
{

protected:
    float currentRotation;
    float rotationSpeed;


public:
    RotationComponent(GameObject& gameObject, float startingRotation, float rotationSpeed);

protected:
    virtual void Rotate(float dt);

public:

    virtual void Update(float dt) override;


};

