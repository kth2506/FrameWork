// ** FrameWork ver 07.19
#define _CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "MainUpdate.h"
#include "CursorManager.h"


int main(void)
{

	system("title ����ȯ - ����");
	
	system("mode con cols=180 lines=45");
	
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


