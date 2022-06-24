#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Headers.h"
#include "Constant.h"

MainUpdate::MainUpdate(){}
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	SceneState = LOGO;
	SceneManager::GetInstance()->SetScene(SceneState);

}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	
	if (dwKey & KEY_UP)
	cout << "KEY_UP" << endl;
	if (dwKey & KEY_DOWN)
	cout << "KEY_DOWN" << endl;
	if (dwKey & KEY_LEFT)
	cout << "KEY_LEFT" << endl;
	if (dwKey & KEY_RIGHT)
	cout << "KEY_RIGHT" << endl;
	if (dwKey & KEY_SPACE)
	cout << "KEY_SPACE" << endl;
	if (dwKey & KEY_CTRL)
	cout << "KEY_CTRL" << endl;
	if (dwKey & KEY_ALT)
	cout << "KEY_ALT" << endl;

	if (dwKey & KEY_ENTER)
	{
		//cout << "KEY_ENTER" << endl;
		if (SceneState > EXIT)
			SceneState = 0;

		SceneManager::GetInstance()->SetScene(SceneState);
		SceneState++;

	}
}

void MainUpdate::Render()
{

}

void MainUpdate::Release()
{

}
