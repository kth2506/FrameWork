#include "Stage.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "StageManager.h"
Stage::Stage() {  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	StageManager::GetInstance()->Initialize();

}

void Stage::Update()
{
	CursorManager::GetInstance()->WriteBuffer(1.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().x);
	CursorManager::GetInstance()->WriteBuffer(6.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().y);
	
	StageManager::GetInstance()->Update();

}

void Stage::Render()
{
	StageManager::GetInstance()->Render();

}

void Stage::Release()
{
	StageManager::GetInstance()->Release();
}

