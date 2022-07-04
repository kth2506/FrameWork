#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Headers.h"
#include "Constant.h"
#include "CursorManager.h"


MainUpdate::MainUpdate(){}
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	CursorManager::GetInstance()->CreateBuffer((float)Console_Width, (float)Console_Height);
	SceneManager::GetInstance()->SetScene(LOGO);

}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();
	CursorManager::GetInstance()->FlippingBuffer();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}
