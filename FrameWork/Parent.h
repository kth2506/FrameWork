#pragma once
#include "Headers.h"

class Parent
{
private:

protected:

	int m_Number;

public:
	virtual void Initialize() = 0;
	virtual void Output() = 0;
	virtual void Update() = 0;
};


