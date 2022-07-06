// ** FrameWork ver11.0 07.06
#define _CRT_SECURE_NO_WARNINGS

#include "Headers.h"
#include "MainUpdate.h"
#include "CursorManager.h"



int main(void)
{
	system("title ����ȯ - ����");

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

// C++�� Ư¡
/*
	 class - ����
	 object ��ü - class�� ��������
*/
#pragma endregion

#pragma region 1. �������� - private
/*
	private:		** �ڱ� �ڽŸ� ��� ����

	protected:	** ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�

	public:		** ������ ����
*/
#pragma endregion

#pragma region 2. ĸ��ȭ - ����� ����ȭ
/* ������ (����) �� ��� (�Լ�) �� �ϳ��� �������� ����ϴ� ��
*/
#pragma endregion

#pragma region 3. �߻�ȭ - ������
/*
		�������� �ʴ� ���¸� �߻� Ŭ���� ��� �Ѵ�.
		����� Ư������ �ʴ� ���
*/
#pragma endregion

#pragma region 4. ��� - ���
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

#pragma region 5. ������ - ������ �پ���	
/*
	�پ��� ���·� ������ �� �ִ�.
*/
#pragma endregion

#pragma region 6. namespace
/*
// ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��
*/
#pragma endregion

#pragma region 7. ������ & �Ҹ��� & ���� ������
/*
class Object
{
private:

public:
	int Number;
	char* Name;
	// ����ڰ� ȣ������ �ʾƵ� �˾Ƽ� ȣ���
	// ������ ���Ŀ� ������ ����
	//Object()
	//{
	//	cout << "������" << endl;
	//};
	//
	//// ����ڰ� ȣ���ϴ� ������ ȣ���� ��
	//// ���ް��� ������ �ڷ����� ���� ���������� ȣ���
	//Object(int _Number)
	//{
	//	cout << "���� ������ : int" << endl;
	//
	//	Number = _Number;
	//};
	//
	//Object(float _Number)
	//{
	//	cout << "���� ������ : float" << endl;
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

	////Ŭ������ �����Ǳ� ������
	~Object()
	{
		cout << "�Ҹ���" << endl;
	};

	void Output()
	{
		cout << Name << endl;
		cout << Number << endl;
	}
};

int main(void)
{

	Object o1(10, (char*)"ȫ�浿");

	Object o2 (o1);

	o1.Name = (char*)"�Ӳ���";
	o2.Output();
	cout << &o1.Name << endl;
	cout << &o2.Name << endl;
	return 0;
}
*/
#pragma endregion

#pragma region 8. ���� ���� , ���� ����
/* 
�˻�
*/
#pragma endregion

#pragma region 9. �����ε� & �������̵�
/*
	�����ε� - ���������
	���ް��� ������ �ڷ����� ���� ���������� ȣ���

	�������̵�(������) - ����� �ϰ� �θ� - �ڽ� ���� ���� �Լ� ������
	�θ� Ŭ������ �ڽ� Ŭ������ ��� ���迡��
	�θ� Ŭ������ �̹� ���ǵ� �Լ��� ���� �̸�����
	�ڽ� Ŭ�������� ������ �ϴ� ���� �ǹ���.
*/
/*
class Object
{
private:

public:

	virtual void Output()
	{
		cout << "��� ����" << endl;

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
		cout << "��� ���� 2" << endl;
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

// �غ���
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
	// ����ڰ� ȣ������ �ʾƵ� �˾Ƽ� ȣ���
	// ������ ���Ŀ� ������ ����
	Object()
	{
	};

	// ����ڰ� ȣ���ϴ� ������ ȣ���� ��
	// ���ް��� ������ �ڷ����� ���� ���������� ȣ���
	Object(int _Number)
	{
		cout << "���� ������ : int" << endl;

		Number = _Number;
	};

	Object(float _Number)
	{
		cout << "���� ������ : float" << endl;

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

	////Ŭ������ �����Ǳ� ������
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

#pragma region 10. ������ �����ε�
/*

// const, & ��� �ñ�
// const - ���ȭ Ű���� , ������ �ϸ� �ȵǴ� ������ ���
// & ������ �޸� �ּҰ�, ���۷���

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

#pragma region 11. ������

/*  [ ������ ]
	1. * ������, & �ּҹ�ȯ ������
	2. �����ͺ������ �����Ҵ�(new) �ؾ���
	3. Ŭ���� & ����ü [ . ](��) �ƴϸ� [ -> ] (ȭ��ǥ) �� ����
	4. �����Ҵ� �ߴٸ� �ݵ�� �Ҵ����� �ؾ��� - �������͵� �������� �ʱ� ������
	(���ÿ� �� Temp �� ���� �޸� ������ �Ͼ�� �ֱ� ������)

	
*/
#pragma endregion

#pragma region 12. inline
/*
	inline - �Լ��� �۵��켱������ �����ִ°�

	Ŭ���� ���� �Լ��� �����ϸ� �ڵ����� inline �Լ��� �ȴ�
	�޸� ���� ���� �Լ��� inline���� ����ϸ� ȿ���� ���ϼ� �ִ�.

*/
#pragma endregion

#pragma region 13. �����Լ�
// ** [virtual] = �����Լ�
// ** �Լ��� ���� [= 0] �� ���̰� �Ǹ� [���� ���� �Լ�] �� �ȴ�.

// ** [���� ���� �Լ�]
// ** virtual �Լ��� �Լ��� ��ü�� ������ ����Ѵ�.

// ** virtual �Լ��� ����ϴ� ����
// ** ���� ���� �Լ� ��� �˻�
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
//// T �ڷ����� �����ִ� �Ű�����
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

