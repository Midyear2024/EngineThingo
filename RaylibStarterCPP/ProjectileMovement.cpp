#include "ProjectileMovement.h"
#include "Transform.h"

ProjectileMovement::ProjectileMovement(GameObject& gameObject, float movementSpeed) : MovementComponent(gameObject, movementSpeed)
{
}

void ProjectileMovement::Move(const float dt)
{
	glm::vec3 movement{ 0, -1, 0 };
	movement *= dt * movementSpeed;
	gameObject->GetTransform()->Translate(movement);
}
