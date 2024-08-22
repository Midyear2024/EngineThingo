#include "Transform.h"
#include "GameObject.h"
#include "Component.h"
#include "Collider.h"
#include "GameManager.h"



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


	for (auto it = children.begin(); it != children.end(); ++it) {
		(*it)->AddParent(parent);
	}

	if (parent) {
		parent->RemoveChild(this);
	}
}

void GameObject::Draw()
{
	//const float length = 100;
	//DrawLine(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], transform->GetWorldPosition()[0] + transform->GetWorldForward()[0] * length, transform->GetWorldPosition()[1] + transform->GetWorldForward()[1] * length, GREEN);
	//DrawLine(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], transform->GetWorldPosition()[0] + transform->GetWorldRight()[0] * length, transform->GetWorldPosition()[1] + transform->GetWorldRight()[1] * length, RED);

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
		
		
		for (auto it = 0; it < components.size(); ++it) {
			components[it]->Update(dt);
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

Component* GameObject::GetComponentOfType(MetaData::ComponentTypes type) const
{
	for (int i = 0; i < components.size(); ++i) {
		if (components[i]->GetType() == type) {
			return components[i];
		}
	}
	return nullptr;
}



void GameObject::AddParent(GameObject* parent)
{
	if (parent == nullptr) {
		this->parent = nullptr;
		transform->AddParent(nullptr);
	}
	else {
		this->parent = parent;
		transform->AddParent(parent->transform);
	}
}

std::vector<GameObject*> GameObject::GetChildren()
{
	return children;
}

void GameObject::Destroy()
{
	OnDestroyed(); //Fire the callback
	beingDestroyed = true;
	GameManager::GetGameManager().RemoveGameObjectFromScene(this);
}

void GameObject::OnDestroyed()
{
}

void GameObject::OnCollision(Collider& other)
{
}
