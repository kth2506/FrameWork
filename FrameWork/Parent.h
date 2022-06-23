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
public:
	void SetNumber(const int& _Number)
	{
		m_Number = _Number + 10;
	}

	int GetNumber() const
	{
		return m_Number;
	}
	
};


