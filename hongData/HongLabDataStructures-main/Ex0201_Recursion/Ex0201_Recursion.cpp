#include <iostream>

using namespace std;

void Func2()
{
	cout << "This is Func2()" << endl;
}

void Func1()
{
	Func2();

	cout << "This is Func1()" << endl;

	// Func2(); // ���� ������ ���� ��� Ȯ��
}

void RecurFunc(int count)
{
	if (count == 0) // <- ���� ����
		return;

	// RecurFunc(count - 1); // <- ����

	cout << count << endl;

	RecurFunc(count - 1); // <- ����

	// ���� ��ġ�� ���� ����� �޶����ϴ�.
}

int main()
{
	// Func1(); // �̸��� �ٸ� �Լ� ȣ��

	RecurFunc(5); // �̸��� ���� �Լ� ȣ��

	return 0;
}