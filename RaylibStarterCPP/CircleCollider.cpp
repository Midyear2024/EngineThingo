#include "CircleCollider.h"
#include "Transform.h"



CircleCollider::CircleCollider(GameObject& gameObject, float radius): radius{radius}
{
	colliderType = MetaData::ColliderType::Circle;
	gameObject.AddComponent(this);
	AddGameObjectReference(gameObject);
	color = GREEN;
}

void CircleCollider::Draw()
{

	DrawCircleLines(gameObject->GetTransform()->GetWorldPosition().x,
		gameObject->GetTransform()->GetWorldPosition().y,
		radius, color);
		
}

void CircleCollider::HandleCollision(Collider& other)
{
	if (other.GetColliderType() == MetaData::Circle) {
		CircleCollider* tempOther = dynamic_cast<CircleCollider*>(&other);
		if (radius + tempOther->GetRadius() >= glm::distance(gameObject->GetTransform()->GetWorldPosition(), tempOther->GetParent()->GetTransform()->GetWorldPosition())) {
			color = RED;
			if(OnCollision)
				OnCollision(*GetParent(), other);
		}
		else {
			color = GREEN;
		}
	}

}



