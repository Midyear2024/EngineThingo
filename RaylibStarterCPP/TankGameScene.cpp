#include "TankGameScene.h"
#include "GameObject.h"
#include "RectRenderer.h"
#include "PlayerTank.h"
#include "Transform.h"
#include "CircleCollider.h"

TankGameScene::TankGameScene(int sceneWidth, int sceneHeight) : Scene(sceneWidth, sceneHeight)
{
    this->AddGameObjectToScene(new PlayerTank(new MyTransform(glm::vec3{ 0, 0, 0 }, 0, glm::vec3{ 1,1,1 }), nullptr));
    
    GameObject* temp = new GameObject(new MyTransform(glm::vec3{ 100,0,0 }));
    new CircleCollider(*temp, 50);
    this->AddGameObjectToScene(temp, false);

}


