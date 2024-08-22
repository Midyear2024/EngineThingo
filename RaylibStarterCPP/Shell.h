#pragma once
#include "GameObject.h"
class Shell :
    public GameObject
{

protected:
    float lifeTime = 5.f;
    float timeAlive = 0.0f;
public:
    Shell(MyTransform* transform, GameObject* parent, float intialSpeed, float intialRotation);


    void Update(float dt) override;

    void OnDestroyed() override;

    void OnCollision(Collider& other) override;
};

