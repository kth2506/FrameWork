#pragma once
#include "UserInterface.h"

class Intro : public UserInterface
{
private:
	bool check;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	int Getcount() { return count; };
public:
	Intro();
	Intro(Transform _Info);
	virtual ~Intro();
};

