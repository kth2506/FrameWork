#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Intro2.h"

Menu::Menu() :count(0)  , pIntro2(){}
Menu::~Menu() {  }

void Menu::Initialize()
{
	str = "Menu";
	count = 0;
	pIntro2 = new Intro2;
	pIntro2->Initialize();
}

void Menu::Update()
{
	count++;
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (pIntro2)
		pIntro2->Update();	

	if (count > 13)
	{
		::Safe_Delete(pIntro2);
		SceneManager::GetInstance()->SetScene(STAGE);
	}

	//if ((dwKey & KEY_ENTER ) && count > 10)
	//{
	//}
	//if (dwKey & KEY_ESCAPE)
	//{
	//	exit(0);
	//}
}

void Menu::Render()
{

	if (pIntro2)
		pIntro2->Render();
	
}

void Menu::Release()
{
}
