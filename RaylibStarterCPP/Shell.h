#pragma once
#include "GameObject.h"
class Shell :
    public GameObject
{

protected:
    float lifeTime = 0.5f;
    float timeAlive = 0.0f;
public:
    Shell(MyTransform* transform, GameObject* parent, float intialSpeed, float intialRotation);


    void Update(float dt) override;
};

