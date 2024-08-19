#include "SpriteRenderer.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer(GameObject& gameObject, std::string filePath, glm::vec3 spriteScale, glm::vec3 drawOrigin, float degreesOffset) : spriteScale{spriteScale}, origin{drawOrigin}, degreesOffset{degreesOffset}
{
	
	sprite = new Sprite{ filePath };
	gameObject.AddComponent(this);
	AddGameObjectReference(gameObject);
}

SpriteRenderer::~SpriteRenderer()
{
	delete sprite;
}

void SpriteRenderer::Draw()
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
		Vector2{ sprite->frameWidth * spriteScale.x * origin.x, sprite->frameHeight * spriteScale.y * origin.y}, radians  * RAD2DEG, WHITE);
}
