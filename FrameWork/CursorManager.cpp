#include "CursorManager.h"
#include "Object.h"

CursorManager* CursorManager::Instance = nullptr;

CursorManager::CursorManager() 
: BufferIndex(0), point() {}
CursorManager::~CursorManager() { DestroyBuffer(); }


POINT CursorManager::GetPoint()
{
	GetCursorPos(&point); // 마우스 위치를 받아온다
	ScreenToClient(GetConsoleWindow(), &point); // 해당 클라이언트 기준으로 좌표를 변환한다
		
	// ** 집환경
	point.x /= 8;
	point.y /= 16;
	// ** 학원환경 
	//point.y /= 18;

	return point;
}

void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{

	CONSOLE_CURSOR_INFO Cursor; // 커서  설정

	Cursor.bVisible = FALSE;	// 커서 안보이게함
	Cursor.dwSize = 1;		// 커서의 사이즈 설정
	
	COORD Size = { (SHORT)_Width, (SHORT)_Height };

	SMALL_RECT rect = { 0, 0 , (SHORT)_Width , (SHORT)_Height	};
	for (int i = 0; i < 2; ++i)
	{
		// ** 버퍼 생성
		hBuffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		// ** 버퍼 사이즈 설정
		SetConsoleScreenBufferSize(hBuffer[i], Size);

		// ** 버퍼가 포함될 윈도우 사이즈 설정
		SetConsoleWindowInfo(hBuffer[i], TRUE, &rect);

		// ** 커서 세팅
		SetConsoleCursorInfo(hBuffer[i], &Cursor);
	}
}

void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	DWORD dw;

	COORD CursorPosition = { SHORT(_x), SHORT(_y) };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// 텍스트 색 변경
	SetColor(_Color);

	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);

}

void CursorManager::WriteBuffer(float _x, float _y, int _Value, int _Color)
{
	DWORD dw;

	COORD CursorPosition = { SHORT(_x), SHORT(_y) };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// 텍스트 색 변경
	SetColor(_Color);

	char Buffer[8];
	_itoa(_Value, Buffer, 10);

	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);
	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);

}

void CursorManager::WriteBuffer(float _x, float _y, float _Value, int _Color)
{

	DWORD dw;

	COORD CursorPosition = { SHORT(_x), SHORT(_y) };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// 텍스트 색 변경
	SetColor(_Color);

	char Buffer[8];
	sprintf(Buffer, "%.3f", _Value);
	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);
	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);

}

void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	DWORD dw;

	COORD CursorPosition = { SHORT(_Position.x), SHORT(_Position.y) };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// 텍스트 색 변경
	SetColor(_Color);

	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, int _Value, int _Color)
{

	DWORD dw;

	COORD CursorPosition = { SHORT(_Position.x), SHORT(_Position.y) };

	// 좌표 이동
	SetConsoleCursorPosition(hBuffer[BufferIndex], CursorPosition);

	// 텍스트 색 변경
	SetColor(_Color);
	char Buffer[8];
	_itoa(_Value, Buffer, 10);

	char* pBuffer = new char[strlen(Buffer)];
	strcpy(pBuffer, Buffer);

	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], pBuffer, (DWORD)strlen(pBuffer), &dw, NULL);
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

	FillConsoleOutputCharacter(hBuffer[BufferIndex], ' ', Console_Width * Console_Height, Coord, &dw);
}

void CursorManager::DestroyBuffer()
{

	for (int i = 0; i < 2; ++i)
		CloseHandle(hBuffer[i]);
}

void CursorManager::SetColor(int _Color)
{
	SetConsoleTextAttribute(hBuffer[BufferIndex], _Color);

}
