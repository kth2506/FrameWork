#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Headers.h"
#include "Constant.h"

MainUpdate::MainUpdate(){}
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	SceneManager::GetInstance()->SetScene(LOGO);

}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}
