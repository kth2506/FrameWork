#pragma once
#include "Scene.h"

class UserInterface;
class Logo : public Scene
{
private:
	UserInterface* pIntro;
	int count;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
	
};

