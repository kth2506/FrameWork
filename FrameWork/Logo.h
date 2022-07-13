#pragma once
#include "Scene.h"

class UserInterface;
class Logo : public Scene
{
private:
	int count;
	UserInterface* pIntro;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Logo();
	virtual ~Logo();
	
};

