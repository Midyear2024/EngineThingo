#pragma once
#include "Component.h"
#include <vector>
#include <functional>
class Collider :
    public Component
{
protected:
   
    Collider() { componentType = MetaData::Collider;  }
    std::vector<Collider*> overlaps;

    MetaData::ColliderType colliderType;
    
    std::function<void(GameObject&, Collider&)> OnCollision;

public:
    virtual void HandleCollision(Collider& other)  = 0;
    MetaData::ColliderType GetColliderType() { return colliderType; }

    void SubscribeToOnCollision(std::function<void(GameObject&, Collider&)> func) { OnCollision = func; }

};

