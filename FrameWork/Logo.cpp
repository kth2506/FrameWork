#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObjectFactory.h"
#include "CursorManager.h"
#include "ProtoType.h"
#include "Intro.h"


Logo::Logo() : Scene() , pIntro() , count(0){  }
Logo::~Logo() { Release(); }


void Logo::Initialize()
{
	str = "Logo";
	count = 0;
	pIntro = new Intro;
	pIntro->Initialize();
}

void Logo::Update()
{
	count++;
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (pIntro)
		pIntro->Update();

	if ((dwKey & KEY_ENTER) && count > 80)
	{
		//::Safe_Delete(pIntro);
		SceneManager::GetInstance()->SetScene(MENU);
	}
	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}
}

void Logo::Render()
{
	if (pIntro)
		pIntro->Render();
}

void Logo::Release()
{
}
