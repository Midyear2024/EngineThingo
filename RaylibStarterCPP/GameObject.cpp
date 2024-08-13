#include "Transform.h"
#include "GameObject.h"




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
}

void GameObject::Draw()
{

	//Than Draw our children
	if (children.empty()) return;
	for (auto it = children.begin(); it != children.end(); ++it) {
		(*it)->Draw();
	}
	
}

void GameObject::Update(float dt)
{
	if (children.empty()) return;
	for (auto it = children.begin(); it != children.end(); ++it) {
		(*it)->Update(dt);
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

void GameObject::AddParent(GameObject* parent)
{
	this->parent = parent;
	transform->AddParent(parent->transform);
}
