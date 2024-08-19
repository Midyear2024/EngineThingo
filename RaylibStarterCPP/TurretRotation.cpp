#include "TurretRotation.h"
#include "Transform.h"

TurretRotation::TurretRotation(GameObject& gameObject, float startingRotation, float rotationSpeed) : RotationComponent(gameObject, startingRotation, rotationSpeed)
{
}

void TurretRotation::Rotate(float dt)
{
	if (IsKeyDown(KEY_Q))
	{
		gameObject->GetTransform()->Rotate(-(rotationSpeed * DEG2RAD) * dt);
	}


	if (IsKeyDown(KEY_E))
	{
		gameObject->GetTransform()->Rotate((rotationSpeed * DEG2RAD) * dt);
	}
}
