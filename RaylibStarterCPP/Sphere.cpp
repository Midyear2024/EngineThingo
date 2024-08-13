#include "Sphere.h"
#include "Transform.h"

Sphere::Sphere(MyTransform* transform, float radius, Color color) : GameObject(transform), radius{radius}, color{color}
{
}

Sphere::Sphere(MyTransform* transform, GameObject* parent, float radius, Color color) : GameObject(transform, parent), radius{radius}, color{color}
{
}

void Sphere::Update(float dt)
{
	
	transform->Translate(glm::vec3{0 , 50 ,0 } * dt);
	transform->Rotate(0.785 * dt);


	GameObject::Update(dt);
}

void Sphere::Draw()
{
	DrawCircle(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], radius * glm::length(transform->GetWorldScale()), color);

	DrawLine(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], transform->GetWorldPosition()[0] + transform->GetWorldForward()[0] * 50, transform->GetWorldPosition()[1] + transform->GetWorldForward()[1] * 50, GREEN);
	DrawLine(transform->GetWorldPosition()[0], transform->GetWorldPosition()[1], transform->GetWorldPosition()[0] + transform->GetWorldRight()[0] * 50, transform->GetWorldPosition()[1] + transform->GetWorldRight()[1] * 50, RED);

	

	GameObject::Draw();
}

