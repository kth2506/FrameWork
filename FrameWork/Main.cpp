// ** FrameWork ver 08.04
#define _CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "MainUpdate.h"
#include "CursorManager.h"


int main(void)
{

	system("title ±Ë≈¬»Ø - 10Minutes Till Dawn");
	
	system("mode con cols=200 lines=50");
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


