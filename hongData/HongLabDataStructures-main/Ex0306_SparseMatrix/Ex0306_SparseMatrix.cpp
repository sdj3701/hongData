#include <iostream>

#include "SparseMatrix.h"

int main()
{
	using namespace std;

	SparseMatrix m1(4, 6, 6); // 4 by 6 matrix, Non-zero term 8��

	// ���ĵ��� ���� ������ �߰�
	m1.SetValue(2, 3, 5.0f);
	m1.SetValue(0, 5, 2.0f);
	m1.SetValue(1, 1, 1.0f);
	m1.SetValue(0, 0, 1.0f);
	m1.SetValue(0, 3, 7.0f);
	m1.SetValue(1, 2, 3.0f);

	// m1.SetValue(2, 3, 4.0f); // <- ����� ���

	m1.PrintTerms();
	m1.Print();

	cout << endl;

	SparseMatrix tr = m1.Transpose(); // ��ġ���

	tr.PrintTerms();
	tr.Print();

	return 0;
}

