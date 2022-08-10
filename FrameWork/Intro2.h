#pragma once
#include "UserInterface.h"

class Intro2 : public UserInterface
{
private:
	bool check;
	int Count;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	int Getcount() { return count; };
public:
	Intro2();
	Intro2(Transform _Info);
	virtual ~Intro2();
};

