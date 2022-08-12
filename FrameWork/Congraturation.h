#pragma once
#include "UserInterface.h"

class Congraturation : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	
public:
	Congraturation();
	Congraturation(Transform _Info);
	virtual ~Congraturation();
};

