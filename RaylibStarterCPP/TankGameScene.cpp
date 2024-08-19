#include "TankGameScene.h"
#include "GameObject.h"
#include "RectRenderer.h"
#include "PlayerTank.h"
#include "Transform.h"

TankGameScene::TankGameScene(int sceneWidth, int sceneHeight) : Scene(sceneWidth, sceneHeight)
{
    this->AddGameObjectToScene(new PlayerTank(new MyTransform(glm::vec3{ 0, 0, 0 }, 0, glm::vec3{ 1,1,1 }), nullptr));

}


