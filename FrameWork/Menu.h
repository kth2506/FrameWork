#pragma once
#include "Scene.h"

class UserInterface;
class Menu : public Scene
{
private:
	UserInterface* pMenu;
	int count;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Menu();
	virtual ~Menu();

};

