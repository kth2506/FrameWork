// ** FrameWork ver02-2 06.21

#include "Child.h"
#include "Bullet.h"

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

// ** 4. 상속 - 상속
 
// ** 5. 다형성 - 형태의 다양함	

// ** 6. namespace
// 별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함


// ** 7. 생성자 & 소멸자 & 복사 생성자

//namespace AAA


//{
//	void Output()
//	{
//		cout << "가나다" << endl;
//	}
//}
//
//namespace BBB
//{
//	void Output()
//	{
//		cout << "라마바" << endl;
//	}
//}


int main(void)
{

	Parent* p[2];

	const int ID_Child = 0;
	const int ID_Bullet = 1;
	p[ID_Child] = new Child;
	p[ID_Bullet] = new Bullet;
	
	for (int i = 0; i < 2; i++)
	{
		p[i]->Initialize();
		p[i]->Output();
	}
	return 0;
}
