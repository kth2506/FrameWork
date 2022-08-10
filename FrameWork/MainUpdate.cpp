#include "Headers.h"
#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Constant.h"
#include "CursorManager.h"
#include "ProtoType.h"


MainUpdate::MainUpdate(){}
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	ProtoType::GetInstance()->Initialize();
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
