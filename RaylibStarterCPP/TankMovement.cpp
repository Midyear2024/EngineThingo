#include "TankMovement.h"
#include "Transform.h"

TankMovement::TankMovement(GameObject& gameObject, float movementSpeed) : MovementComponent(gameObject, movementSpeed)
{
}

void TankMovement::Move(const float dt)
{
	glm::vec3 movement = glm::vec3{ 0,0,0 };

	if (IsKeyDown(KEY_W)) {
		movement.y -= movementSpeed * dt;
	}
	else if (IsKeyDown(KEY_S)) {
		movement.y += movementSpeed * dt;
	}
	gameObject->GetTransform()->Translate(movement);
}
