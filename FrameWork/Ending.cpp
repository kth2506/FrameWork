#include "Ending.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Outtro2.h"
Ending::Ending() {  }
Ending::~Ending() { Release(); }

void Ending::Initialize()
{
	str = "Ending";

	pOuttro2 = new Outtro2;
	pOuttro2->Initialize();
}

void Ending::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if(pOuttro2)
	pOuttro2->Update();

	if ((dwKey & KEY_ENTER))
	{
		exit(0);
	}
}

void Ending::Render()
{
	if (pOuttro2)
		pOuttro2->Render();
}

void Ending::Release()
{
}
