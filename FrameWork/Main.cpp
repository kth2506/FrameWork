// ** FrameWork ver02-1 06.21

#include <iostream>

using namespace std;
// C++의 특징
// class - 집합
// ** 1. 정보은닉	 - private
// ** 2. 캡슐화 - 기능의 고유화
// ** 3. 추상화 - 포괄적
// ** 4. 상속 - 상속
// ** 5. 다형성 - 형태의 다양함	
// ** 6. namespace
// object 객체 - class로 만들어야함

namespace AAA
{
	void Output()
	{
		cout << "가나다" << endl;
	}
}

namespace BBB
{
	void Output()
	{
		cout << "라마바" << endl;
	}
}

using BBB::Output;
class Parent
{
private:
	// ** 자기 자신만 사용 가능

protected:
	// ** 상속간에 공개된 상태. 비상속 클래스 사용불가. 외부 사용 불가

public:
	// ** 공개된 상태

};

class Child : public Parent
{
};

int main(void)
{
	Output();
	return 0;
}
