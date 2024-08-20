#pragma once
#include "Scene.h"
class GameManager {



protected:
	
	Scene* currentScene;
	~GameManager();

	std::vector<GameObject*> garbage;

	void DeleteGarbage();
	const float garbageCollectionInterval = 2.0f;
	float garbageTimer = 0.0f;

public:
	static GameManager& GetGameManager();

	void AddSceneToManager(Scene* newScene);
	void AddCreatedGameObjectToCurrentScene(GameObject* gameObjectToAdd, bool parentToSceneRoot = true);
	void RemoveGameObjectFromScene(GameObject* gameObjectToRemove);

	void HandleGarbageCollectionTick(float dt);
};