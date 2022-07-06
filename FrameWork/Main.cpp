// ** FrameWork ver11.0 07.06
#define _CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "MainUpdate.h"
#include "CursorManager.h"



int main(void)
{
	system("title 김태환 - 게임");

	system("mode con cols=120 lines=30");

	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");
			Main.Update();
			Main.Render();
		}

	}

	return 0;
}




#pragma region C++

// C++의 특징
/*
	 class - 집합
	 object 객체 - class로 만들어야함
*/
#pragma endregion

#pragma region 1. 정보은닉 - private
/*
	private:		** 자기 자신만 사용 가능

	protected:	** 상속간에 공개된 상태. 비상속 클래스 사용불가. 외부 사용 불가

	public:		** 공개된 상태
*/
#pragma endregion

#pragma region 2. 캡슐화 - 기능의 고유화
/* 데이터 (변수) 와 기능 (함수) 를 하나의 묶음으로 사용하는 것
*/
#pragma endregion

#pragma region 3. 추상화 - 포괄적
/*
		존재하지 않는 형태를 추상 클래스 라고 한다.
		대상이 특정되지 않는 경우
*/
#pragma endregion

#pragma region 4. 상속 - 상속
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
#pragma endregion

#pragma region 5. 다형성 - 형태의 다양함	
/*
	다양한 형태로 존재할 수 있다.
*/
#pragma endregion

#pragma region 6. namespace
/*
// 별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함
*/
#pragma endregion

#pragma region 7. 생성자 & 소멸자 & 복사 생성자
/*
class Object
{
private:

public:
	int Number;
	char* Name;
	// 사용자가 호출하지 않아도 알아서 호출됨
	// 생성된 직후에 생성자 생성
	//Object()
	//{
	//	cout << "생성자" << endl;
	//};
	//
	//// 사용자가 호출하는 시점에 호출이 됨
	//// 전달값의 개수와 자료형에 따라서 선택적으로 호출됨
	//Object(int _Number)
	//{
	//	cout << "복사 생성자 : int" << endl;
	//
	//	Number = _Number;
	//};
	//
	//Object(float _Number)
	//{
	//	cout << "복사 생성자 : float" << endl;
	//
	//	Number = (int)_Number;
	//};

	Object(int _Number, char* _Obj) : Number(_Number)
	{
		Number = _Number;
		Name = new char[strlen(_Obj) + 1];
		strcpy(Name, _Obj);
	};


	//Object(Object* _Obj)
	//{
	//	Name = _Obj->Name;
	//}

	////클래스가 삭제되기 직전에
	~Object()
	{
		cout << "소멸자" << endl;
	};

	void Output()
	{
		cout << Name << endl;
		cout << Number << endl;
	}
};

int main(void)
{

	Object o1(10, (char*)"홍길동");

	Object o2 (o1);

	o1.Name = (char*)"임꺽정";
	o2.Output();
	cout << &o1.Name << endl;
	cout << &o2.Name << endl;
	return 0;
}
*/
#pragma endregion

#pragma region 8. 깊은 복사 , 얕은 복사
/* 
검색
*/
#pragma endregion

#pragma region 9. 오버로딩 & 오버라이딩
/*
	오버로딩 - 복사생성자
	전달값의 개수와 자료형에 따라서 선택적으로 호출됨

	오버라이딩(다형성) - 상속을 하고 부모 - 자식 간에 같은 함수 재정의
	부모 클래스와 자식 클래스의 상속 관계에서
	부모 클래스에 이미 정의된 함수를 같은 이름으로
	자식 클래스에서 재정의 하는 것을 의미함.
*/
/*
class Object
{
private:

public:

	virtual void Output()
	{
		cout << "비어 있음" << endl;

	}
	void Output(string _str)
	{
		cout << _str << endl;
	}
};

class Object2 : public Object
{
public:
	void Output() override
	{
		cout << "비어 있음 2" << endl;
	}

	void Output(string _str)
	{
		cout << _str << "2" << endl;
	}
};

int main(void)
{
	Object* o = new Object2;
	o->Output();
	o->Output("33");

	Object2 o2;
	o2.Output();
	o2.Output("asdf");

	Object o3;
	o3.Output();
	o3.Output("asdf");

	return 0;
}
*/

// 해보기
/*

struct tagInfo
{
	int Number;
};

class Object
{
private:

protected:
	tagInfo m_Info;

public:
	int Number = 0;
	char* Name = 0;

public:
	virtual Object* Clone() = 0;

public:
	// 사용자가 호출하지 않아도 알아서 호출됨
	// 생성된 직후에 생성자 생성
	Object()
	{
	};

	// 사용자가 호출하는 시점에 호출이 됨
	// 전달값의 개수와 자료형에 따라서 선택적으로 호출됨
	Object(int _Number)
	{
		cout << "복사 생성자 : int" << endl;

		Number = _Number;
	};

	Object(float _Number)
	{
		cout << "복사 생성자 : float" << endl;

		Number = (int)_Number;
	};

	Object(int _Number, char* _Obj) : Number(_Number)
	{
		Number = _Number;
		Name = new char[strlen(_Obj) + 1];
		strcpy(Name, _Obj);
	};

	Object(tagInfo _Info) : m_Info(_Info)
	{

	};

	//Object(Object* _Obj)
	//{
	//	Name = _Obj->Name;
	//}

	////클래스가 삭제되기 직전에
	~Object()
	{
	};

	void Output()
	{
		cout << Name << endl;
		cout << Number << endl;
	}
};

class Player : public Object
{
public:
	virtual Object* Clone() override
	{
		return new Player(*this);
	}
	void Output() { cout << m_Info.Number << endl; }

public:
	Player()
	{
		m_Info.Number = 10;
	};

	Player(tagInfo _Info) : Object(_Info)
	{

	};

	~Player() { };
};

map <string, Object*> ProtoTypeObject;
Object* GetObject(string _str);


int main(void)
{
	tagInfo Info;
	Info.Number = 10;

	ProtoTypeObject["Player"] = new Player(Info);
	for (int i = 0; i < 10; ++i)
	{
		ProtoTypeObject["Player"][i].Number = Info.Number++;
	}
	Object* pProtoObj = GetObject("Player");

	Object* pPlayer = GetObject("Player")->Clone();


	if (pProtoObj != nullptr)
		pPlayer = pProtoObj->Clone();

	for (int i = 0 ; i < 10; ++i)
	{
	cout << pPlayer<< endl;
	}
	return 0;
}

Object* GetObject(string _str)
{
	map<string, Object*>::iterator iter = ProtoTypeObject.find(_str);

	if (iter == ProtoTypeObject.end())
		return nullptr;
	else
		return iter->second;

}

*/
#pragma endregion

#pragma region 10. 연산자 오버로딩
/*

// const, & 사용 시기
// const - 상수화 키워드 , 변경을 하면 안되는 곳에서 사용
// & 변수의 메모리 주소값, 레퍼런스

struct tagInfo
{

	int Number = 0;

	tagInfo() {};
	tagInfo(int _Number) : Number(_Number) {};
};

class Object
{
private:
	tagInfo Info;

public:
	Object& operator+=(const Object& _Obj)
	{
		Info.Number += _Obj.Info.Number;
		return *this;
	}

	Object& operator++()
	{
		Info.Number++;
		return *this;
	}

	Object& operator--()
	{
		Info.Number--;
		return *this;
	}
public:
	Object() { };
	Object(tagInfo _Info) : Info(_Info) { };
	~Object() { };

	void Output()
	{
		cout << Info.Number << endl;
	}
};

int main(void)
{
	Object o1(tagInfo(10));
	Object o2(o1);

	o1.Output();
	o2 += o1;
	++o2;
	--o2;
	o2.Output();

	return 0;
}

*/
#pragma endregion

#pragma region 11. 포인터

/*  [ 포인터 ]
	1. * 데이터, & 주소반환 연산자
	2. 포인터변수라면 동적할당(new) 해야함
	3. 클래스 & 구조체 [ . ](점) 아니면 [ -> ] (화살표) 로 접근
	4. 동적할당 했다면 반드시 할당해제 해야함 - 빠져나와도 삭제되지 않기 때문에
	(스택에 들어간 Temp 와 같이 메모리 누수가 일어날수 있기 때문에)

	
*/
#pragma endregion

#pragma region 12. inline
/*
	inline - 함수의 작동우선순위를 높여주는것

	클래스 내에 함수를 정의하면 자동으로 inline 함수가 된다
	메모리 해제 등의 함수를 inline으로 사용하면 효율을 높일수 있다.

*/
#pragma endregion

#pragma region 13. 가상함수
// ** [virtual] = 가상함수
// ** 함수의 끝에 [= 0] 을 붙이게 되면 [순수 가상 함수] 가 된다.

// ** [순수 가상 함수]
// ** virtual 함수가 함수의 몸체가 없을때 사용한다.

// ** virtual 함수를 사용하는 이유
// ** 순수 가상 함수 사용 검색
#pragma endregion

#pragma region 14. Singleton
// ** Singleton
//
//class Singleton
//{	
//private:
//	static Singleton* Instance;
//public:
//	static Singleton* GetInstance()
//	{
//		if (Instance == nullptr)
//			Instance = new Singleton();
//		return Instance;
//	}
//
//private:
//	int Number;
//public:
//	int GetNumber() const { return Number; }
//	void SetNumber(const int& _Number) { Number = _Number; }
//	
//private:
//	Singleton() : Number(0) {};
//public:
//	~Singleton() {};
//};
//
//Singleton* Singleton::Instance = nullptr;
#pragma endregion

#pragma region 15. template

//
//template <typename T1, typename T2>
//class Temp
//{
//public:
//	static T1* Func()
//	{
//		return new T2;
//	}
//
//};
//
//
//class A
//{
//public:
//	int Number;
//
//};
//
//
//// T 자료형을 보내주는 매개변수
//template <typename T>
//T* Func()
//{
//	return new T;
//}
//
//
//int main(void)
//{
//	A* a = Func<A>();
//
//	a->Number = 10;
//
//	return 0;
//}


#pragma endregion

