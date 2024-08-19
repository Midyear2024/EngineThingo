#pragma once
#include "GameObject.h"
class Shell :
    public GameObject
{
public:
    Shell(MyTransform* transform, GameObject* parent, float intialSpeed, float intialRotation);



};

