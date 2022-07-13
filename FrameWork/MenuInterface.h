#pragma once
#include "UserInterface.h"

class MenuInterface : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	MenuInterface();
	MenuInterface(Transform _Info);
	virtual ~MenuInterface();
};

