#include "GameManager.h"

GameManager::~GameManager()
{
    delete currentScene;
}

GameManager& GameManager::GetGameManager()
{
    static GameManager instance;
    return instance;
}

void GameManager::AddSceneToManager(Scene* newScene)
{
    if (currentScene != nullptr) {
        delete currentScene;
    }
    currentScene = newScene;

}

void GameManager::AddCreatedGameObjectToCurrentScene(GameObject* gameObjectToAdd, bool parentToSceneRoot)
{
    currentScene->AddGameObjectToScene(gameObjectToAdd, parentToSceneRoot);
}
