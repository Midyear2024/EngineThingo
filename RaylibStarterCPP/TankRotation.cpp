#include "TankRotation.h"
#include "Transform.h"

TankRotation::TankRotation(GameObject& gameObject, float startingRotation, float rotationSpeed) : RotationComponent(gameObject, startingRotation, rotationSpeed)
{
}

void TankRotation::Rotate(float dt)
{
	if (IsKeyDown(KEY_A))
	{
		gameObject->GetTransform()->Rotate(-((rotationSpeed * DEG2RAD)) * dt);
	}


	if (IsKeyDown(KEY_D))
	{
		gameObject->GetTransform()->Rotate((rotationSpeed * DEG2RAD) * dt);
	}

}
