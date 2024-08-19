#include "Shell.h"
#include "SpriteRenderer.h"
#include "ProjectileMovement.h"
Shell::Shell(MyTransform* transform, GameObject* parent, float intialSpeed, float intialRotation) : GameObject(transform, parent)
{
	new SpriteRenderer(*this, "Resources/Sprites/Bullet.png", { 1,1,1 }, { 0.5f, 0.5f,0.5f }, 0);
	new ProjectileMovement(*this, 100.0f);

}
