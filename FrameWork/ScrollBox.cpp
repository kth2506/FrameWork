#define _CRT_SECURE_NO_WARNINGS

#include "ScrollBox.h"
#include "CursorManager.h"
#include "InputManager.h"
ScrollBox::ScrollBox(){}
ScrollBox::ScrollBox(Transform _Info){}
ScrollBox::~ScrollBox(){}

void ScrollBox::Initialize()
{


	strKey = "ScrollBox";
	TextureList.emplace_back("忙式式式式式式式式式式式式式式式忖");
	for (int i = 0; i < 28; ++i)
	TextureList.emplace_back("弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	TextureList.emplace_back("戌式式式式式式式式式式式式式式式戎");

	TransInfo.Position = Vector3(float(120 / 2), 10.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(34.0f, 17.0f);
}

int ScrollBox::Update()
{
	//DWORD dwKey = InputManager::GetInstance()->GetKey();
	//
	//auto iter = TextureList.begin();
	//++iter;
	//
	//if (dwKey & KEY_CTRL)
	//{
	//	if (TransInfo.Position.y + TransInfo.Scale.y < 29)
	//	{
	//		TextureList.insert(iter, "弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	//		++TransInfo.Scale.y;
	//	}
	//}
	return 0;
}

void ScrollBox::Render()
{

	for (int i = 0; i < TextureList.size(); ++i)
	{
		char Temp[sizeof TextureList[i].c_str()];
		strcpy(Temp, TextureList[i].c_str());
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Temp);
	}


}

void ScrollBox::Release()
{
}
