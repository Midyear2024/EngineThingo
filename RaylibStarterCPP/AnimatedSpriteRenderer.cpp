#include "AnimatedSpriteRenderer.h"
#include "Transform.h"

AnimatedSpriteRenderer::AnimatedSpriteRenderer(GameObject& gameObject, std::string filePath, glm::vec3 spriteScale, glm::vec3 drawOrigin, float degreesOffset, int totalFrames, int totalLines) 
{
	this->origin = drawOrigin; 
	this->degreesOffset = degreesOffset;
	this->spriteScale = spriteScale;
	
	totalNumberOfFramesPerLine = totalFrames;
	totalNumberOfLines = totalLines;


	sprite = new Sprite{ filePath, totalNumberOfFramesPerLine, totalNumberOfLines};
	gameObject.AddComponent(this);
	AddGameObjectReference(gameObject);
	
	currentFrame = 0;
	currentLine = 0;
}

void AnimatedSpriteRenderer::Update(float dt)
{
	frameCounter++;
	if (frameCounter > 2) {
		currentFrame++;
		if (currentFrame >= totalNumberOfFramesPerLine) {
			currentFrame = 0;
			currentLine++;
			if (currentLine >= totalNumberOfLines) {
				currentLine = 0;
			}

		}
		frameCounter = 0;
	}

	sprite->frameRect.x = sprite->frameWidth * currentFrame;
	sprite->frameRect.y = sprite->frameHeight * currentLine;


}

void AnimatedSpriteRenderer::Draw()
{
	if (sprite == nullptr) return;

	destinationRect = Rectangle{
		gameObject->GetTransform()->GetWorldPosition().x,
		gameObject->GetTransform()->GetWorldPosition().y,
		sprite->frameWidth * spriteScale.x,
		sprite->frameHeight * spriteScale.y
	};

	auto radians = std::atan2(gameObject->GetTransform()->GetWorldRight().y, gameObject->GetTransform()->GetWorldRight().x);
	radians += (degreesOffset * DEG2RAD);

	DrawTexturePro(sprite->sprite,
		sprite->frameRect,
		destinationRect,
		Vector2{ sprite->frameWidth * spriteScale.x * origin.x, sprite->frameHeight * spriteScale.y * origin.y }, radians * RAD2DEG, WHITE);

}

