#pragma once
#include "Collider.h"
class CircleCollider :
    public Collider
{
protected:
    float radius; 

public:
    CircleCollider(GameObject& gameObject, float radius);

    virtual void Draw() override;
    virtual void HandleCollision(Collider& other) override;

    float GetRadius() const { return radius; }

    Color color;
};

