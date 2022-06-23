#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate(){}
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	state = LOGO;
	SceneManager::GetInstance()->SetScene(state);

}

void MainUpdate::Update()
{
	++Count;
	if (Count <= 1000)
	{
		Count = 0;
		state++;

		SceneManager::GetInstance()->SetScene(state);
	}
}

void MainUpdate::Render()
{

}

void MainUpdate::Release()
{

}
