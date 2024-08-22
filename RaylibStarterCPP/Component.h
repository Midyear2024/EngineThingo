#pragma once
#include "GameObject.h"
#include "MetaData.h"


class Component {
	

protected:
	GameObject* gameObject;
	MetaData::ComponentTypes componentType;

public:
	virtual void Draw(){}
	virtual void Update(float dt){}

	void AddGameObjectReference(GameObject& gameObject) { this->gameObject = &gameObject; }
	MetaData::ComponentTypes GetType() const { return componentType; }
	GameObject* GetParent() const {return gameObject; }


};