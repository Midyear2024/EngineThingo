#pragma once
#include "GameObject.h"
class PlayerTank : public GameObject {


protected:
	GameObject* fireTransform;
	GameObject* Turret;

	const float fireRate = 0.5f;

	float fireRateTimer = 0;

public:
	PlayerTank(MyTransform* transform, GameObject* parent);
	virtual void Update(float dt) override;

	void FireShell();
	bool HandleFireRate(float dt);

	void OnDestroyed() override;
	
};