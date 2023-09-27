#include <iostream>

#include "../shared/MaxHeap.h"

using namespace std;

struct Patient
{
	int severity; // <- ������, ������ ���� 1������ Ű(key)�� ����
	int time;	  // <- �����ð�, ������ ���� 2������ Ű(key)�� ����, �������� ���� ���� ���� �� ����
	const char* name;

	// �켱���� �������� ���� �� a >= b ������ ��ȯ�ϴ� �Լ�
	friend bool operator >= (const Patient& a, const Patient& b)
	{
		if (a.severity == b.severity) // �켱������ ���� ���� �ð��� �������� �ٽ� �Ǵ� (������)
			return a.time <= b.time;   // ���ڷν� time�� ���� ���� ���� �Դٴ� �ǹ̴ϱ� ���� �켱������ �� ����.
		else
			return a.severity > b.severity; // �켱������ ū �� ����
	}

	friend bool operator < (const Patient& a, const Patient& b)
	{
		return !(a >= b); // ���� ! ���� (operator >= Ȱ��) 
	}

	friend std::ostream& operator << (std::ostream& os, const Patient& p)
	{
		// TODO: �ʿ��ϸ� ����
		return os;
	}
};

int main()
{
	// ���޽�
	MaxHeap<Patient> h;

	// �켱������ �� ���� ȯ�� ���� ġ��
	// �� ������ ���(severity�� ū ���) �켱������ ����.
	// ������ ���ſ� ������ �����ϴٸ�(severity�� ���ٸ�) ���� �� ȯ�� ���� ġ��(time�� ���� ȯ�� ����)

	h.Push({ 1, 0, "Ironman" });   // ������ 1�� Ironman �ð� 0�� ����
	h.Push({ 1, 1, "Nick Fury" }); // ������ 1�� Nick Fury �ð� 1�� ����
	h.Push({ 3, 2, "Hulk" });      // ������ 3�� Hulk �ð� 2�� ����

	cout << h.Top().name << endl;  // �������� ���� Hulk ���� ġ��
	h.Pop();

	cout << h.Top().name << endl;  // �������� ���������� ���� ������ Ironman
	h.Pop();

	h.Push({ 2, 3, "Blue Beetle" });

	cout << h.Top().name << endl;  // �ʰ� ���������� �������� ���� Blue Beetle
	h.Pop();

	cout << h.Top().name << endl;  // ���������� Nick Fury
	h.Pop();

	/* ��� ����
	Hulk
	Ironman
	Blue Beetle
	Nick Fury
	*/

	return 0;
}
