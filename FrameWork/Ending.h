#pragma once
#include "Scene.h"

class UserInterface;
class Ending : public Scene
{
private:
	UserInterface* pOuttro2;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Ending();
	virtual ~Ending();

};

