#pragma once
#include "Component.h"
#include "glm/glm.hpp"
class RectRenderer : public Component
{

protected:
	glm::vec3 extents;
	glm::vec3 origin;
	float rotation;
	Color color;



public:
	RectRenderer();
	RectRenderer(GameObject& gameObject);
	RectRenderer(int width, int height, float rotation, Color color);
	RectRenderer(glm::vec3 extents, float rotation, Color color);
	RectRenderer(GameObject& gameObject, glm::vec3 extents,glm::vec3 origin, float rotation, Color color);


public:

	virtual void Draw() override;





};

