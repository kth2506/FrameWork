#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr){}
SceneManager::~SceneManager() {	Release(); }

void SceneManager::SetScene(SCENEID _SceneState)
{

	if (SceneState != nullptr)
		::Safe_Delete(SceneState);


	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:		
		SceneState = new Stage;
		break;

	case EXIT:
		exit(0);
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


