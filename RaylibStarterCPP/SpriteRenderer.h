#pragma once
#include "Component.h"
#include "string"

struct Sprite {
    
   
    Sprite(std::string filePath) {
        sprite = LoadTexture(filePath.c_str());
        frameWidth = sprite.width;
        frameHeight = sprite.height;
        frameRect = Rectangle{ 0,0, frameWidth, frameHeight };
    }
    Sprite(std::string filePath, int frames, int lines) {
        sprite = LoadTexture(filePath.c_str());
        frameWidth = (float)sprite.width / frames;
        frameHeight = (float)sprite.height / lines;
        frameRect = Rectangle{ 0,0, frameWidth, frameHeight };
    }
    ~Sprite() {
        UnloadTexture(sprite);
    }
    Texture2D sprite;

    float frameWidth;
    float frameHeight;

    Rectangle frameRect;
};


class SpriteRenderer :
    public Component
{

protected:
    Sprite* sprite;
    glm::vec3 spriteScale;
    glm::vec3 origin;
    float degreesOffset;
    Rectangle destinationRect;

public:
    SpriteRenderer() = default;
    SpriteRenderer(GameObject& gameObject,std::string filePath, glm::vec3 spriteScale, glm::vec3 drawOrigin, float degreesOffset);
    ~SpriteRenderer();
public:
    virtual void Draw() override;
};

