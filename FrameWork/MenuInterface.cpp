#define _CRT_SECURE_NO_WARNINGS

#include "MenuInterface.h"
#include "CursorManager.h"
#include "InputManager.h"
MenuInterface::MenuInterface() {}
MenuInterface::MenuInterface(Transform _Info) {}
MenuInterface::~MenuInterface() {}

void MenuInterface::Initialize()
{


	strKey = "MenuInterface";
	TextureList.emplace_back((char*)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	for (int i = 0; i < 28; ++i)
		TextureList.emplace_back((char*)"弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	TextureList.emplace_back((char*)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

	TransInfo.Position = Vector3(float(180 / 2) - 32.5f, 10.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(34.0f, 17.0f);
}

int MenuInterface::Update()
{
	
	return 0;
}

void MenuInterface::Render()
{

	for (int i = 0; i < (int)TextureList.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			TextureList[i]);
	}


}

void MenuInterface::Release()
{
}
