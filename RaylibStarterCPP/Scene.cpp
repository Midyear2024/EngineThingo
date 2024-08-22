#include "Scene.h"
#include "GameObject.h"
#include "Transform.h"

Scene::Scene(int sceneWidth, int sceneHeight) : sceneWidth {sceneWidth}, sceneHeight {sceneHeight}
{
	InitWindow(sceneWidth, sceneHeight, "raylib [core] example - basic window");

	sceneRoot = new GameObject(new MyTransform(glm::vec3(sceneWidth / 2, sceneHeight / 2, 0)));
	allObjectsInScene.push_back(sceneRoot);
}

Scene::~Scene()
{
	for (int i = 0; i < allObjectsInScene.size(); ++i) {
		delete allObjectsInScene[i];
	}
}

void Scene::AddGameObjectToScene(GameObject* objectToAdd, bool parentToSceneRoot)
{
	allObjectsInScene.push_back(objectToAdd);
	
	if (parentToSceneRoot) {
		objectToAdd->AddParent(sceneRoot);
		sceneRoot->AddChild(objectToAdd);
	}
	if (objectToAdd->HasChildren()) {
		for (auto child : objectToAdd->GetChildren()) {
			AddGameObjectToScene(child, false);
		}
	}

}

void Scene::RemoveGameObjectFromScene(GameObject* objectToRemove)
{
	auto it = std::find(allObjectsInScene.begin(), allObjectsInScene.end(), objectToRemove);
	allObjectsInScene.erase(it);
}

std::vector<GameObject*> Scene::GetAllObjectsInScene() const
{
	return allObjectsInScene;
}

void Scene::Update(float dt)
{
	if(sceneRoot != nullptr)
		for (int i = 0; i < allObjectsInScene.size(); ++i) {
			allObjectsInScene[i]->Update(dt);
		}
}

void Scene::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	//if (sceneRoot != nullptr)
	//	sceneRoot->Draw();
	for (int i = 0; i < allObjectsInScene.size(); ++i) {
		allObjectsInScene[i]->Draw();
	}
	EndDrawing();
}
