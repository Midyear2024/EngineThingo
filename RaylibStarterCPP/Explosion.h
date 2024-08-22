#pragma once
#include "GameObject.h"
#include "string"
class Explosion :
    public GameObject
{
public:
    Explosion(MyTransform* transform, GameObject* parent, std::string filePath, int totalFrames, int totalLines);



};

