#pragma once
#include "Scene.h"
class Object;

class UserInterface;
class Stage : public Scene
{
private:
	UserInterface* pMenuInterface;
	UserInterface* pDiePlayer;

	bool Check;
	int count;
	Object* pPlayer;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
	void Enable_UI();

public:

public:
	Stage();
	virtual ~Stage();

};

