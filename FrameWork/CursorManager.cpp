#include "CursorManager.h"
#include "Object.h"

CursorManager* CursorManager::Instance = nullptr;

CursorManager::CursorManager() 
: BufferIndex(0){}
CursorManager::~CursorManager() {}

void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	
	CONSOLE_CURSOR_INFO Cursor; // Ŀ��  ����


	Cursor.bVisible = FALSE;	// Ŀ�� �Ⱥ��̰���
	Cursor.dwSize = 1;		// Ŀ���� ������ ����
	
	COORD Size = { (SHORT)_Width, (SHORT)_Height };

	SMALL_RECT rect = { 0, 0 , _Width , _Height	};

	for (int i = 0; i < 2; ++i)
	{
		// ** ���� ����
		hBuffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		// ** ���� ������ ����
		SetConsoleScreenBufferSize(hBuffer[i], Size);

		// ** ���۰� ���Ե� ������ ������ ����
		SetConsoleWindowInfo(hBuffer[i], TRUE, &rect);

		// ** Ŀ�� ����
		SetConsoleCursorInfo(hBuffer[i], &Cursor);
	}

}

void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	DWORD dw;

	COORD CursorPosition = { SHORT(_x), SHORT(_y) };


	// ��ǥ �̵�
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// ���ۿ� ����
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);

}

void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	DWORD dw;

	COORD CursorPosition = { SHORT(_Position.x), SHORT(_Position.x) };

	// ��ǥ �̵�
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// ���ۿ� ����
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[BufferIndex]);
	BufferIndex = !BufferIndex;

	ClearBuffer();

}

void CursorManager::ClearBuffer()
{
	DWORD dw;
	COORD Coord = { 0 , 0 };

	FillConsoleOutputCharacter(hBuffer[BufferIndex], ' ', 120 * 30, Coord, &dw);
}

void CursorManager::DestroyBuffer()
{
}