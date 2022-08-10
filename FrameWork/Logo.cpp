#include "Logo.h"
#include "Intro.h"
#include "SceneManager.h"
#include "InputManager.h"

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
		SceneManager::GetInstance()->SetScene(STAGE);
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
