#pragma once
#include "UserInterface.h"

class Outtro : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Outtro();
	Outtro(Transform _Info);
	virtual ~Outtro();
};

