// ** FrameWork ver03t 06.22

#include "Parent.h"
#include "Child.h"
#include "Bullet.h"
#include <stdlib.h>

// C++�� Ư¡
// class - ����
// object ��ü - class�� ��������
// ** 1. ��������	 - private
 /*
	private:		** �ڱ� �ڽŸ� ��� ����

	protected:	** ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�

	public:		** ������ ����
*/

// ** 2. ĸ��ȭ - ����� ����ȭ
// ������ (����) �� ��� (�Լ�) �� �������� ����ϴ� ��

// ** 3. �߻�ȭ - ������
//		�������� �ʴ� ���¸� �߻� Ŭ���� ��� �Ѵ�.
//		����� Ư������ �ʴ� ���

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
//	�پ��� ���·� ������ �� �ִ�.

// ** 6. namespace
// ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��

// ** 7. ������ & �Ҹ��� & ���� ������

// ** 8. ���� ���� , ���� ����

// ** 9. �����ε� & �������̵�

// ** 10. ������ �����ε�

// ** 11. ������


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


