#pragma once
#include "Parent.h"

class Bullet : public Parent
{
	void Initialize()
	{
		m_Number = 100;
	}
	void Update()
	{
		m_Number += 100;
	}
	void Output()
	{
		cout << m_Number << endl;
	}
};

