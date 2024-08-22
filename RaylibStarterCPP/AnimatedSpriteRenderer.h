#pragma once
#include "SpriteRenderer.h"
class AnimatedSpriteRenderer :
    public SpriteRenderer
{

public:
    AnimatedSpriteRenderer(GameObject& gameObject,
        std::string filePath,
        glm::vec3 spriteScale,
        glm::vec3 drawOrigin,
        float degreesOffset,
        int totalFrames,
        int totalLines, 
        bool looping,
        bool destroyObjectOnFinish);
protected:
    
    
    int currentFrame;
    int currentLine;

    int totalNumberOfFramesPerLine;
    int totalNumberOfLines;

    int frameCounter = 0;

    bool looping;
    bool destroyObjectOnFinish;

    bool playing;

public:

    void Update(float dt) override;
    void Draw() override;



};

