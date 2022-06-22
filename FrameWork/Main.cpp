// ** FrameWork ver03t 06.22

#include "Parent.h"
#include "Child.h"
#include "Bullet.h"
#include <stdlib.h>

// C++의 특징
// class - 집합
// object 객체 - class로 만들어야함
// ** 1. 정보은닉	 - private
 /*
	private:		** 자기 자신만 사용 가능

	protected:	** 상속간에 공개된 상태. 비상속 클래스 사용불가. 외부 사용 불가

	public:		** 공개된 상태
*/

// ** 2. 캡슐화 - 기능의 고유화
// 데이터 (변수) 와 기능 (함수) 를 묶음으로 사용하는 것

// ** 3. 추상화 - 포괄적
//		존재하지 않는 형태를 추상 클래스 라고 한다.
//		대상이 특정되지 않는 경우

// ** 4. 상속 - 상속
/*

class AAA
{
private:
protected:
	string m_str = "AAA";

public:

	void Initialize()
	{
		m_str = "AAA";
	}
	void Output()
	{
		cout << m_str << endl;
	}
};

class BBB : public AAA
{
private:
	string m_str = "BBB";

public:

	void Initialize()
	{
		m_str = "BBB";
	}
};
class CCC : public AAA
{
private:

public:
	void Initialize()
	{
		m_str = "CCC";
	}
};

*/

// ** 5. 다형성 - 형태의 다양함	
//	다양한 형태로 존재할 수 있다.

// ** 6. namespace
// 별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함

// ** 7. 생성자 & 소멸자 & 복사 생성자

// ** 8. 깊은 복사 , 얕은 복사

// ** 9. 오버로딩 & 오버라이딩

// ** 10. 연산자 오버로딩

// ** 11. 포인터


enum {ID_Child, ID_Bullet};

int main(void)
{

	Parent* p[2];

	p[ID_Child] = new Child;
	p[ID_Bullet] = new Bullet;

	for (int i = 0; i < 2; ++i)
		p[i]->Initialize();

	while (true)
	{
		system("cls");

		for (int i = 0; i < 2; ++i)
			p[i]->Update();

		for (int i = 0; i < 2; ++i)
			p[i]->Output();

	}
	return 0;
}


