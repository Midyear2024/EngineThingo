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
	const float length = 100;
	DrawLine(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], transform->GetWorldPosition()[0] + transform->GetWorldForward()[0] * length, transform->GetWorldPosition()[1] + transform->GetWorldForward()[1] * length, GREEN);
	DrawLine(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], transform->GetWorldPosition()[0] + transform->GetWorldRight()[0] * length, transform->GetWorldPosition()[1] + transform->GetWorldRight()[1] * length, RED);

	//Draw attached components
	if (!components.empty()) {
		for (auto it = components.begin(); it != components.end(); ++it) {
			(*it)->Draw();
		}
	}

}

void GameObject::Update(float dt)
{
	if (!components.empty()) {
		for (auto it = components.begin(); it != components.end(); ++it) {
			(*it)->Update(dt);
		}
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

void GameObject::RemoveChild(GameObject* child)
{
	children.erase(std::find(children.begin(), children.end(), child));
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

void GameObject::OnDestroy()
{
	delete transform;

	for (int i = 0; i < components.size(); ++i) {
		delete components[i];
	}
	components.clear();

	if (parent) {
		parent->RemoveChild(this);
	}
	beingDestroyed = true;
}
