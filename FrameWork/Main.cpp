// ** FrameWork ver02-2 06.21

#include "Child.h"
#include "Bullet.h"

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

// ** 4. ��� - ���
 
// ** 5. ������ - ������ �پ���	

// ** 6. namespace
// ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��


// ** 7. ������ & �Ҹ��� & ���� ������

//namespace AAA


//{
//	void Output()
//	{
//		cout << "������" << endl;
//	}
//}
//
//namespace BBB
//{
//	void Output()
//	{
//		cout << "�󸶹�" << endl;
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
