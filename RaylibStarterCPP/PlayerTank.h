#pragma once
#include "GameObject.h"
class PlayerTank : public GameObject {



public:
	PlayerTank(MyTransform* transform, GameObject* parent);
	virtual void Update(float dt) override;

	void FireShell();
};