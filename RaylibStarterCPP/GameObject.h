#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <raylib.h>
#include "MetaData.h"

class Collider;
class MyTransform;
class Component;
class GameObject {


protected:
		
	MyTransform* transform;

	GameObject* parent;
	std::vector<GameObject*> children;
	std::vector<Component*> components;
	
	bool beingDestroyed = false;
	

public:
	GameObject();
	GameObject(MyTransform* transform);
	GameObject(GameObject* parent);
	GameObject(MyTransform* transform, GameObject* parent);


	virtual ~GameObject();


	virtual void Draw();
	virtual void Update(float dt);

	MyTransform* GetTransform();
	void AddChild(GameObject* child);
	void RemoveChild(GameObject* child);

	void AddComponent(Component* toAdd);
	Component* GetComponentOfType(MetaData::ComponentTypes type) const;

	void AddParent(GameObject* parent);

	bool HasChildren() const { return children.size() > 0; }
	bool IsBeingDestroyed() const { return beingDestroyed; }

	std::vector<GameObject*> GetChildren();

	void Destroy();
	virtual void OnDestroyed();

	virtual void OnCollision(Collider& other);


};