#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Ending.h"
SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr){}
SceneManager::~SceneManager() { Release(); }


void SceneManager::SetScene(SCENEID _SceneState)
{

	if (SceneState != nullptr)
		::Safe_Delete(SceneState);

	switch (_SceneState)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;
	case SCENEID::MENU:
		SceneState = new Menu;
		break;
	case SCENEID::STAGE:
		SceneState = new Stage;
		break;
	case SCENEID::ENDING:
		SceneState = new Ending;
		break;
	case SCENEID::EXIT:
		exit(0);
		break;
	default:
		break;
	}
	SceneState->Initialize();

}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState);
}


