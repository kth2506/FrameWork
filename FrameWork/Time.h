#pragma once
#include "UserInterface.h"

class Time : public UserInterface
{
private:
	int count;
	int Minutes;
	int Second;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Time();
	Time(Transform _Info);
	virtual ~Time();
};

