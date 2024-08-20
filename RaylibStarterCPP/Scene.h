#pragma once
#include <vector>
class GameObject;
class Scene {


protected:
	GameObject* sceneRoot;
	std::vector<GameObject*> allObjectsInScene;
	int sceneWidth;
	int sceneHeight;

public:
	Scene(int sceneWidth, int sceneHeight);
	~Scene();


	void AddGameObjectToScene(GameObject* objectToAdd, bool parentToSceneRoot = true);
	void RemoveGameObjectFromScene(GameObject* objectToRemove);

	virtual void Update(float dt);
	virtual void Draw();

};