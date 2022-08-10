#pragma once
#include "UserInterface.h"

class Outtro2 : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Outtro2();
	Outtro2(Transform _Info);
	virtual ~Outtro2();
};

