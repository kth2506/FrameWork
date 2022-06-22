// ** FrameWork ver03 06.22
#include "Parent.h"
#include "Child.h"
#include "Bullet.h"
#include <stdlib.h>
#include <cstring>

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



#pragma region C++

// C++의 특징
/*
	 class - 집합
	 object 객체 - class로 만들어야함
*/

// 1. 정보은닉	 - private
/*
	private:		** 자기 자신만 사용 가능

	protected:	** 상속간에 공개된 상태. 비상속 클래스 사용불가. 외부 사용 불가

	public:		** 공개된 상태
*/

// ** 2. 캡슐화 - 기능의 고유화
/* 데이터 (변수) 와 기능 (함수) 를 묶음으로 사용하는 것
*/

// ** 3. 추상화 - 포괄적
/*
		존재하지 않는 형태를 추상 클래스 라고 한다.
		대상이 특정되지 않는 경우
*/

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
/*
	다양한 형태로 존재할 수 있다.
*/

// ** 6. namespace
/*
// 별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함
*/

// ** 7. 생성자 & 소멸자 & 복사 생성자
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

// ** 8. 깊은 복사 , 얕은 복사
/* 
검색
*/

// ** 9. 오버로딩 & 오버라이딩
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


// ** 10. 연산자 오버로딩
/*

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

// ** 11. 포인터

#pragma endregion

