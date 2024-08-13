#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <raylib.h>

class MyTransform;

class GameObject {


protected:
		
	MyTransform* transform;

	GameObject* parent;
	std::vector<GameObject*> children;

	
	void AddParent(GameObject* parent);
	

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



};