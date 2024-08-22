#include "Explosion.h"
#include "AnimatedSpriteRenderer.h"

Explosion::Explosion(MyTransform* transform, GameObject* parent, std::string filePath, int totalFrames, int totalLines) : GameObject(transform, parent)
{
	new AnimatedSpriteRenderer(*this, filePath, { 1,1,1 }, { 0.5f, 0.5f,0.5f }, 0, totalFrames, totalLines, false, true);
}
