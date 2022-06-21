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
	
	// ** [virtual] = 가상함수
	// ** 함수의 끝에 [= 0] 을 붙이게 되면 [순수 가상 함수] 가 된다.

	// ** [순수 가상 함수]
	// ** virtual 함수가 함수의 몸체가 없을때 사용한다.

	// ** virtual 함수를 사용하는 이유
	// ** 순수 가상 함수 사용 검색
};

