#pragma once
#include "Headers.h"

class UserInterface;
class UserInterfaceManager
{
private:
	UserInterface* pTime;
	UserInterface* pOuttro;
	UserInterface* pHpBar;
	UserInterface* pWarning;
	UserInterface* pLevel;
private:
	static UserInterfaceManager* Instance;
public:
	static UserInterfaceManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new UserInterfaceManager();
		return Instance;
	}
private:
public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	UserInterfaceManager();
public:
	~UserInterfaceManager();

};
