#include "Shell.h"
#include "SpriteRenderer.h"
#include "ProjectileMovement.h"
#include "GameManager.h"
Shell::Shell(MyTransform* transform, GameObject* parent, float intialSpeed, float intialRotation) : GameObject(transform, parent)
{
	new SpriteRenderer(*this, "Resources/Sprites/Bullet.png", { 1,1,1 }, { 0.5f, 0.5f,0.5f }, 0);
	new ProjectileMovement(*this, 500.0f);

}

void Shell::Update(float dt)
{
	timeAlive += dt;
	if (timeAlive >= lifeTime) {
		GameManager::GetGameManager().RemoveGameObjectFromScene(this);
	}

	GameObject::Update(dt);
}
