// ** FrameWork ver01 06.20

#include <iostream>

using namespace std;

// C++�� Ư¡


  
// class - ����
// ** 1. ��������	 - private
// ** 2. ĸ��ȭ - ����� ����ȭ
// ** 3. �߻�ȭ - ������
// ** 4. ��� - ���
// ** 5. ������ - ������ �پ���	

// object ��ü - class�� ��������
void co();
void Initalize(int& _Number);

struct AAA
{
	int Number = 0;

};

class BBB
{
private:
	int m_iNumber = 0;

public:
	void Initialize()
	{
		m_iNumber = 0;
	}
	// ** �����͸� ����ϴ°��� ���������� ������ �Ұ�.
	int GetNumber() { return m_iNumber; }
	// ** �����ϴ°��� ���������� ������ �Ұ�
	void SetNumber(int _Number) { m_iNumber = _Number; }

};

int main(void)
{
	AAA a;
	a.Number = 10;
	BBB b;

	int c = b.GetNumber();
	b.SetNumber(50);

	c = b.GetNumber();
	b.Initialize();

	cout << a.Number << endl;
	Initalize(a.Number);

	cout << a.Number << endl;
	cout << c << endl;

	co();
	return 0;
}

void co()
{
	BBB a;

	cout << a.GetNumber() << endl;
}

void Initalize(int& _Number)
{
	_Number = 0;
}