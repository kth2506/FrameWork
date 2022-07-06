#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Menu::Menu() {  }
Menu::~Menu() {  }

void Menu::Initialize()
{
}

void Menu::Update()
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}

	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}
}

void Menu::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		60, 15, (char*)"Menu", 15
	);
}

void Menu::Release()
{
}
