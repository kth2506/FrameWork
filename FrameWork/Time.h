#pragma once
#include "UserInterface.h"

class Time : public UserInterface
{
private:
	map<int, vector<char*>> MS;
	int Minutes;
	int Second2;
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

