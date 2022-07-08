// ** FrameWork ver13.0 07.08
#define _CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "MainUpdate.h"
#include "CursorManager.h"


int main(void)
{

	system("title 김태환 - 게임");
	
	system("mode con cols=120 lines=30");
	
	MainUpdate Main;
	Main.Initialize();
	
	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
	
			system("cls");
			Main.Update();
			Main.Render();
		}
	}

	return 0;
}


