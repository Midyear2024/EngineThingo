#pragma once
#include "Component.h"
class MovementComponent :
    public Component
{
public:
    MovementComponent(GameObject& gameObject, float movementSpeed);

protected:
    float movementSpeed;
protected:


    virtual void Move(const float dt);
public:
    virtual void Update(float dt) override;
};

