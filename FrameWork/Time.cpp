#define _CRT_SECURE_NO_WARNINGS

#include "Time.h"
#include "CursorManager.h"
#include "InputManager.h"
Time::Time() : Minutes(0), Second(0) , count(0) {}
Time::Time(Transform _Info) {}
Time::~Time() {}

void Time::Initialize()
{

	strKey = "Time";

	Minutes = 10;
	Second = 0;
	count = 0;
	TextureList.emplace_back((char*)"忙式式式式式式式式式式式式式式式忖");
	TextureList.emplace_back((char*)"戌式式式式式式式式式式式式式式式戎");

	/*TransInfo.Position = Vector3(float(120 / 2), 10.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(34.0f, 17.0f);*/
}

int Time::Update()
{
	CursorManager::GetInstance()->WriteBuffer(90.0f, 2.0f, Minutes);
	CursorManager::GetInstance()->WriteBuffer(93.0f, 2.0f, Second);
	count++;
	if (count % 14 == 0)
	{
		Second--;
	}

	if (Second == -1)
	{
		Minutes--;
		Second = 59;
	}
	return 0;
}

void Time::Render()
{

	//for (int i = 0; i < (int)TextureList.size(); ++i)
	//{
	//	CursorManager::GetInstance()->WriteBuffer(
	//		TransInfo.Position.x ,
	//		TransInfo.Position.y  + i,
	//		TextureList[i]);
	//}


}

void Time::Release()
{
}
