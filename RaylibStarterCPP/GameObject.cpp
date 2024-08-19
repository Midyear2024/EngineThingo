#include "Transform.h"
#include "GameObject.h"
#include "Component.h"



GameObject::GameObject() : GameObject(new MyTransform())
{
	
}

GameObject::GameObject(MyTransform* transform) : transform{transform}
{
	parent = nullptr;
}
GameObject::GameObject(GameObject* parent)
{
	
	transform->AddParent(parent->GetTransform());

}

GameObject::GameObject(MyTransform* transform, GameObject* parent) : transform{transform}, parent{parent}
{

	if(parent !=  nullptr)
		parent->AddChild(this);
}

GameObject::~GameObject()
{
	delete transform;

	for (int i = 0; i < components.size(); ++i) {
		delete components[i];
	}
	components.clear();
}

void GameObject::Draw()
{

	//Draw attached components
	if (!components.empty()) {
		for (auto it = components.begin(); it != components.end(); ++it) {
			(*it)->Draw();
		}
	}

	//Than Draw our children
	if (children.empty()) return;
	for (auto it = children.begin(); it != children.end(); ++it) {
		(*it)->Draw();
	}
	
}

void GameObject::Update(float dt)
{
	if (!components.empty()) {
		for (auto it = components.begin(); it != components.end(); ++it) {
			(*it)->Update(dt);
		}
	}

	if (children.empty()) return;
	for (int i = 0; i < children.size(); ++i) {
		children[i]->Update(dt);
	}
}

MyTransform* GameObject::GetTransform()
{
	return transform;
}

void GameObject::AddChild(GameObject* child)
{
	children.push_back(child);
	child->AddParent(this);
}

void GameObject::AddComponent(Component* toAdd)
{
	toAdd->AddGameObjectReference(*this);
	components.push_back(toAdd);
}



void GameObject::AddParent(GameObject* parent)
{
	this->parent = parent;
	transform->AddParent(parent->transform);
}

std::vector<GameObject*> GameObject::GetChildren()
{
	return children;
}
