#include "Logo.h"

#include "SceneManager.h"
#include "InputManager.h"
void Logo::Initialize()
{
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
	cout << "Logo" << endl;
}

void Logo::Release()
{
}

Logo::Logo()
{
}

Logo::~Logo()
{
}
