#include "PlayerTank.h"
#include "RectRenderer.h"
#include "TankMovement.h"
#include "TankRotation.h"
#include "TurretRotation.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Shell.h"
#include "GameManager.h"

PlayerTank::PlayerTank(MyTransform* transform, GameObject* parent) : GameObject(transform, parent)
{

    new SpriteRenderer(*this, "Resources/Sprites/Tank.png", glm::vec3{ 0.5f,0.5f,1 }, glm::vec3{ 0.5f, 0.5f, 0 }, 180.0f);
    new TankMovement(*this, 100);
    new TankRotation(*this, 0, 100);

    GameObject* Turret = new GameObject(new MyTransform(glm::vec3{ 0, 0, 0 }, 0, glm::vec3{ 1,1,1 }), this);
    new SpriteRenderer(*Turret, "Resources/Sprites/GunTurret.png", glm::vec3{ 0.5f,0.5f,1 }, glm::vec3{ 0.5f, 0.8f, 0 }, 0);
    new TurretRotation(*Turret, 0, 100);
    
    /*this->AddGameObjectToScene(Tank, true);
    this->AddGameObjectToScene(Turret, false);*/
}

void PlayerTank::Update(float dt)
{
    if (IsKeyDown(KEY_SPACE)) {
        FireShell();
    }
    
   
    GameObject::Update(dt);
}

void PlayerTank::FireShell()
{
    auto radians = std::atan2(GetTransform()->GetWorldRight().y, GetTransform()->GetWorldRight().x);
    GameManager::GetGameManager().AddCreatedGameObjectToCurrentScene
    (new Shell(new MyTransform(transform->GetLocalPosition() + transform->GetLocalForward() * -75.f, radians), nullptr, 100.0f, 0.0f));
}
