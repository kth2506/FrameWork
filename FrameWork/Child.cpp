#include "Child.h"

void Child::Initialize()
{
	m_Number = 10;
}

void Child::Update()
{
	m_Number += 10;
}

void Child::Output()
{
	cout << m_Number << endl;
}
