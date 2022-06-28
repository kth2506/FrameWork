#pragma once

#include "Headers.h"

class CursorManager
{
public:
	static void SetCursorPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE) , Pos);

	}
	
	static void Draw(float _x, float _y, string _str)
	{
		SetCursorPosition(_x, _y);
		cout << _str;
	}
};


//
//
//private:
//	static CursorManager* Instance;
//public:
//	static CursorManager* GetInstance()
//	{
//		if (Instance == nullptr)
//			Instance = new CursorManager();
//		return Instance;
//	}
//
//
//private:
//	CursorManager();
//public:
//	~CursorManager();
