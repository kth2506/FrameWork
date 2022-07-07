#pragma once
#include "UserInterface.h"

class Intro : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Intro();
	Intro(Transform _Info);
	virtual ~Intro();
};

