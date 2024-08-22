#include "PlayerTank.h"
#include "TankMovement.h"
#include "TankRotation.h"
#include "TurretRotation.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Shell.h"
#include "GameManager.h"
#include "CircleCollider.h"
#include <iostream>

PlayerTank::PlayerTank(MyTransform* transform, GameObject* parent) : GameObject(transform, parent)
{

    //Set Up tank base
    new SpriteRenderer(*this, "Resources/Sprites/Tank.png", glm::vec3{ 0.5f,0.5f,1 }, glm::vec3{ 0.5f, 0.5f, 0 }, 180.0f);
    new TankMovement(*this, 100);
    new TankRotation(*this, 0, 100);
    new CircleCollider(*this, 50);
   
    //Set up turret
    Turret = new GameObject(new MyTransform(glm::vec3{ 0, 0, 0 }, 0, glm::vec3{ 1,1,1 }), this);
    new SpriteRenderer(*Turret, "Resources/Sprites/GunTurret.png", glm::vec3{ 0.5f,0.5f,1 }, glm::vec3{ 0.5f, 0.8f, 0 }, 0);
    new TurretRotation(*Turret, 0, 100);

    //Set up where shells spawn from
    fireTransform = new GameObject(new MyTransform(glm::vec3{ 0, -75, 0 }, 0, glm::vec3{ 1,1,1 }), Turret);

}

void PlayerTank::Update(float dt)
{
    if (HandleFireRate(dt) && IsKeyReleased(KEY_SPACE)) {
        FireShell();
        fireRateTimer = fireRate;
    }
    
    GameObject::Update(dt);
}

void PlayerTank::FireShell()
{
    auto radians = std::atan2(fireTransform->GetTransform()->GetWorldRight().y, fireTransform->GetTransform()->GetWorldRight().x);
    GameManager::GetGameManager().AddCreatedGameObjectToCurrentScene
    (new Shell(new MyTransform(fireTransform->GetTransform()->GetWorldPosition(), radians), nullptr, 100.0f, 0.0f), false);

}

bool PlayerTank::HandleFireRate(float dt)
{
    if (fireRateTimer > 0) {
        fireRateTimer -= dt;
        return false;
    }
    return true;
}

void PlayerTank::OnDestroyed()
{
    fireTransform->Destroy();
    Turret->Destroy();
}


