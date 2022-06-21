// ** FrameWork ver01 06.20

#include <iostream>

using namespace std;

// C++의 특징


  
// class - 집합
// ** 1. 정보은닉	 - private
// ** 2. 캡슐화 - 기능의 고유화
// ** 3. 추상화 - 포괄적
// ** 4. 상속 - 상속
// ** 5. 다형성 - 형태의 다양함	

// object 객체 - class로 만들어야함
void co();
void Initalize(int& _Number);

struct AAA
{
	int Number = 0;

};

class BBB
{
private:
	int m_iNumber = 0;

public:
	void Initialize()
	{
		m_iNumber = 0;
	}
	// ** 데이터를 사용하는것은 가능하지만 수정은 불가.
	int GetNumber() { return m_iNumber; }
	// ** 수정하는것은 가능하지만 참조는 불가
	void SetNumber(int _Number) { m_iNumber = _Number; }

};

int main(void)
{
	AAA a;
	a.Number = 10;
	BBB b;

	int c = b.GetNumber();
	b.SetNumber(50);

	c = b.GetNumber();
	b.Initialize();

	cout << a.Number << endl;
	Initalize(a.Number);

	cout << a.Number << endl;
	cout << c << endl;

	co();
	return 0;
}

void co()
{
	BBB a;

	cout << a.GetNumber() << endl;
}

void Initalize(int& _Number)
{
	_Number = 0;
}