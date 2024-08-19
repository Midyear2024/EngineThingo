#pragma once
#include "glm/glm.hpp"
class MyTransform {

private:
	glm::mat4 localTransform;
	glm::mat4 worldTransform;
	glm::vec3 localScale;
	glm::vec3 worldScale;


	MyTransform* parentObject;


	 void CalculateWorldTransform();
	

public:

	static constexpr glm::vec3 WORLD_FORWARD{ 0.0f, 1.0f, 0.0f };
	static constexpr glm::vec3 WORLD_RIGHT{ 1.0f, 0.0f, 0.0f };


	MyTransform();
	MyTransform(glm::vec3 pos);
	MyTransform(glm::vec3 pos, float rot);
	MyTransform(glm::vec3 pos, float angle, glm::vec3 scale);

	glm::vec3 GetLocalPosition() const;
	glm::vec3 GetWorldPosition();
	
	glm::vec3 GetLocalRight() const;
	glm::vec3 GetLocalForward() const;
	glm::vec3 GetLocalUp() const;
	
	glm::vec3 GetWorldRight();
	glm::vec3 GetWorldForward();
	glm::vec3 GetWorldUp();
	
	glm::mat4 GetWorldTransform();
	glm::mat4 GetLocalTransform() const;

	float GetLocalScaleX() const; 
	float GetWorldScaleX();

	float GetLocalScaleY() const;
	float GetWorldScaleY();

	float GetLocalScaleZ() const;
	float GetWorldScaleZ();

	glm::vec3 GetWorldScale();
	glm::vec3 GetLocalScale() const;




	void AddParent(MyTransform* parent);

	void Translate(glm::vec3 translateVector);
	void Rotate(float radians, glm::vec3 axis = {0,0,0});
	void Scale(glm::vec3 scale);

	void SetPosition(glm::vec3 newPosition);


	


};