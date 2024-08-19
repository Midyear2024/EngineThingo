#include "RectRenderer.h"
#include <raylib.h>
#include "GameObject.h"
#include "Transform.h"
#include "glm/ext.hpp"

RectRenderer::RectRenderer() : RectRenderer(glm::vec3{100, 100, 0}, 0, MAGENTA)
{}

RectRenderer::RectRenderer(GameObject& gameObject) : RectRenderer(gameObject, glm::vec3{ 100, 100, 0 }, glm::vec3{ 0,0,0 }, 0, MAGENTA)
{}

RectRenderer::RectRenderer(int width, int height,float rotation,  Color color) : RectRenderer(glm::vec3{ width, height, 0 }, rotation, color)
{}

RectRenderer::RectRenderer(glm::vec3 extents, float rotation, Color color) : extents{extents}, rotation {rotation}, color{color}
{}

RectRenderer::RectRenderer(GameObject& gameObject, glm::vec3 extents, glm::vec3 origin, float rotation, Color color) : extents{ extents }, origin{ origin },  rotation { rotation }, color{ color }
{
	gameObject.AddComponent(this);
	AddGameObjectReference(gameObject);
}





void RectRenderer::Draw()
{
	Rectangle rect;
	rect.x = gameObject->GetTransform()->GetWorldPosition().x;
	rect.y = gameObject->GetTransform()->GetWorldPosition().y;
	rect.width = extents.x;
	rect.height = extents.y;

	auto radians = std::atan2(gameObject->GetTransform()->GetWorldRight().y, gameObject->GetTransform()->GetWorldRight().x);

	DrawRectanglePro(rect, Vector2{ extents.x * origin.x, extents.y * origin.y }, radians * RAD2DEG, color);


}
