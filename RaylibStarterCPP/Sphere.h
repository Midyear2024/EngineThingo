#pragma once
#include "GameObject.h"
#include "raylib.h"


class MyTransform;
class Sphere :
    public GameObject
{

public: 
    Sphere(MyTransform* transform, float radius, Color color);
    Sphere(MyTransform* transform, GameObject* parent, float radius, Color color);

    virtual void Update(float dt) override;
    virtual void Draw() override;
protected:
    float radius;
    Color color;
    char c = 0;


};

