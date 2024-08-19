#pragma once
#include "Scene.h"
class GameManager {



protected:
	

	Scene* currentScene;
	~GameManager();

public:
	static GameManager& GetGameManager();

	void AddSceneToManager(Scene* newScene);
	void AddCreatedGameObjectToCurrentScene(GameObject* gameObjectToAdd, bool parentToSceneRoot = true);



};