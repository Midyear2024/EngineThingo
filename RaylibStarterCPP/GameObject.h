#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <raylib.h>

class MyTransform;
class Component;
class GameObject {


protected:
		
	MyTransform* transform;

	GameObject* parent;
	std::vector<GameObject*> children;
	std::vector<Component*> components;
	
	

public:
	GameObject();
	GameObject(MyTransform* transform);
	GameObject(GameObject* parent);
	GameObject(MyTransform* transform, GameObject* parent);


	~GameObject();


	virtual void Draw();
	virtual void Update(float dt);

	MyTransform* GetTransform();
	void AddChild(GameObject* child);

	void AddComponent(Component* toAdd);

	void AddParent(GameObject* parent);

	bool HasChildren() { return children.size() > 0; }

	std::vector<GameObject*> GetChildren();

};