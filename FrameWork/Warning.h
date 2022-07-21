#pragma once
#include "UserInterface.h"

class Warning : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Warning();
	Warning(Transform _Info);
	virtual ~Warning();
};

