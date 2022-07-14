#pragma once
#include "Headers.h"


class Object;
class UserInterface;
class StageManager
{
private:
	int Check;
	int count;
	Object* pPlayer;
	UserInterface* pUI;
	UserInterface* pTime;
private:
	static StageManager* Instance;
public:
	static StageManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new StageManager();
		return Instance;
	}
private:
public:
	void Initialize();
	void Update();
	void Render();
	void Enable_UI();
	void Release();

private:
	StageManager();
public:
	~StageManager();

};

