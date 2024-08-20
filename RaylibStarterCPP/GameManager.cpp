#include "GameManager.h"

GameManager::~GameManager()
{
    delete currentScene;
}

void GameManager::DeleteGarbage()
{
    for (int i = 0; i < garbage.size(); ++i) {
       delete garbage[i];
    }
    garbage.clear();
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

void GameManager::RemoveGameObjectFromScene(GameObject* gameObjectToRemove)
{
    garbage.push_back(gameObjectToRemove);
    currentScene->RemoveGameObjectFromScene(gameObjectToRemove);
}

void GameManager::HandleGarbageCollectionTick(float dt)
{
    if(garbageTimer < garbageCollectionInterval)
        garbageTimer += dt;
    if (!garbage.empty() && garbageTimer >= garbageCollectionInterval) {
        DeleteGarbage();
    }

}

