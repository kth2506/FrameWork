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

// C++�� Ư¡
/*
	 class - ����
	 object ��ü - class�� ��������
*/

// 1. ��������	 - private
/*
	private:		** �ڱ� �ڽŸ� ��� ����

	protected:	** ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�

	public:		** ������ ����
*/

// ** 2. ĸ��ȭ - ����� ����ȭ
/* ������ (����) �� ��� (�Լ�) �� �������� ����ϴ� ��
*/

// ** 3. �߻�ȭ - ������
/*
		�������� �ʴ� ���¸� �߻� Ŭ���� ��� �Ѵ�.
		����� Ư������ �ʴ� ���
*/

// ** 4. ��� - ���
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

// ** 5. ������ - ������ �پ���	
/*
	�پ��� ���·� ������ �� �ִ�.
*/

// ** 6. namespace
/*
// ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��
*/

// ** 7. ������ & �Ҹ��� & ���� ������
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

// ** 8. ���� ���� , ���� ����
/* 
�˻�
*/

// ** 9. �����ε� & �������̵�
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


// ** 10. ������ �����ε�
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

// ** 11. ������

#pragma endregion

