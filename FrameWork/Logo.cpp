#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObjectFactory.h"

Logo::Logo() : Scene() {  }
Logo::~Logo() {  }


void Logo::Initialize()
{
	str = "Logo";

	
	ObjectManager::GetInstance()->AddObject
	(ObjectFactory<Player>::CreateObject());

}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
}

void Logo::Render()
{
	cout << str << endl;
}

void Logo::Release()
{
}