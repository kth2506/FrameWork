// ** FrameWork ver02-1 06.21

#include <iostream>

using namespace std;
// C++�� Ư¡
// class - ����
// ** 1. ��������	 - private
// ** 2. ĸ��ȭ - ����� ����ȭ
// ** 3. �߻�ȭ - ������
// ** 4. ��� - ���
// ** 5. ������ - ������ �پ���	
// ** 6. namespace
// object ��ü - class�� ��������

namespace AAA
{
	void Output()
	{
		cout << "������" << endl;
	}
}

namespace BBB
{
	void Output()
	{
		cout << "�󸶹�" << endl;
	}
}

using BBB::Output;
class Parent
{
private:
	// ** �ڱ� �ڽŸ� ��� ����

protected:
	// ** ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�

public:
	// ** ������ ����

};

class Child : public Parent
{
};

int main(void)
{
	Output();
	return 0;
}
