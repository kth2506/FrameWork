#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "MenuInterface.h"

Menu::Menu() :count(0)  ,pMenu(){}
Menu::~Menu() {  }

void Menu::Initialize()
{
	str = "Menu";
	count = 0;
	pMenu = new MenuInterface;
	pMenu->Initialize();
}

void Menu::Update()
{
	count++;
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (pMenu)
		pMenu->Update();

	if ((dwKey & KEY_ENTER )&& count > 10)
	{
		::Safe_Delete(pMenu);
		SceneManager::GetInstance()->SetScene(STAGE);
	}
	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}
}

void Menu::Render()
{

	if (pMenu)
		pMenu->Render();
	
}

void Menu::Release()
{
}
