#pragma once

#include "Headers.h"

class CursorManager
{
private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;
		return Instance;
	}
private:
	POINT point;
	int BufferIndex;			// ** ������ �ε��� ������ ���� ����
	HANDLE hBuffer[2];	// 2���� ����
public:
	POINT GetPoint();
	Vector3 GetVector() { 
		GetPoint();
		return Vector3((float)point.x, (float)point.y); }
	void CreateBuffer(const int& _Width,const int& _Height);		// ���۸� ����
	void WriteBuffer(float _x, float _y, char* _str, int _Color = 15);		// �׸��� ����  
	void WriteBuffer(Vector3 _Position, char* _str, int _Color = 15);		// �׸��� ����  
	void FlippingBuffer();			// ���� ��ȯ
	void ClearBuffer();				// �׷��� ���� ����
	void DestroyBuffer();			// ���� ����
	void SetColor(int _Color);	// ���ڿ� ���� ����
private:
	CursorManager();
public:
	~CursorManager();
};