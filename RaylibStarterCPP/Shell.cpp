#include "Shell.h"
#include "AnimatedSpriteRenderer.h"
#include "ProjectileMovement.h"
#include "GameManager.h"
#include "Explosion.h"
#include "transform.h"
#include "CircleCollider.h"
#include <iostream>
Shell::Shell(MyTransform* transform, GameObject* parent, float intialSpeed, float intialRotation) : GameObject(transform, parent)
{
	new SpriteRenderer(*this, "Resources/Sprites/Bullet.png", { 1,1,1 }, { 0.5f, 0.5f,0.5f }, 0);
	new ProjectileMovement(*this, 500.0f);
	auto temp = new CircleCollider(*this, 20);
	temp->SubscribeToOnCollision(&GameObject::OnCollision);

}

void Shell::Update(float dt)
{
	timeAlive += dt;
	if (timeAlive >= lifeTime) {
		Destroy();
	}

	GameObject::Update(dt);
}

void Shell::OnDestroyed()
{
	GameManager::GetGameManager().AddCreatedGameObjectToCurrentScene
	(new Explosion(
		new MyTransform(
			transform->GetWorldPosition()), nullptr, "Resources/Sprites/explosion.png", 5, 5), false);

}

void Shell::OnCollision(Collider& other)
{
	other.GetParent()->Destroy();
	Destroy();
}


