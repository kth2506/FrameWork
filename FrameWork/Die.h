#pragma once
#include "UserInterface.h"

class Die : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Die();
	Die(Transform _Info);
	virtual ~Die();
};

