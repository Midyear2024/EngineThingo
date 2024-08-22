#include "GameManager.h"
#include "TankGameScene.h"
#include "Collider.h"

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

void GameManager::HandleCollisions()
{
    std::vector<GameObject*> objects = currentScene->GetAllObjectsInScene();
    if (objects.size() <= 1) return;

    std::vector<Collider*> colliders;
   
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if ((*it)->IsBeingDestroyed()) continue;
        
        Component* temp = (*it)->GetComponentOfType(MetaData::Collider);
        
        if (temp != nullptr) {
            colliders.push_back(dynamic_cast<Collider*>(temp));
        }
    }
    if (colliders.size() <= 1) return;

    for (auto it = 0; it < colliders.size(); ++it) {
        for (auto oit = 0; oit < colliders.size(); ++oit) {
            if (it == oit) continue;
           

           
            colliders[it]->HandleCollision(*colliders[oit]);
        }
    }

}

void GameManager::Init()
{
    currentScene = new TankGameScene(600, 600);
}

void GameManager::Run(float dt)
{
    currentScene->Update(dt);
    HandleCollisions();
    // Draw
    currentScene->Draw();

    HandleGarbageCollectionTick(dt);
}


