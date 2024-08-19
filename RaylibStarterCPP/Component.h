#pragma once
#include "GameObject.h"


class Component {
	

protected:
	GameObject* gameObject;


public:
	virtual void Draw(){}
	virtual void Update(float dt){}

	void AddGameObjectReference(GameObject& gameObject) { this->gameObject = &gameObject; }


};