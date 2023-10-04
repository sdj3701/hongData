#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

void RecurPermutations(char* arr, int left, int right)
{
	// arr[left], ..., arr[right]

	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		// ��Ʈ
		// - for, swap(), ���ȣ��
		// - ���� ���������� swap() ����
		// - right�� ����

		// TODO:
	}
}

int main()
{
	/* a �� ������ ���� (Permutations)

		a
	*/

	/* ab �� ������ ���� (Permutations)

		a b
		b a
	*/

	/*  abc 3 ������ ���� (Permutations)

		a b c
		a c b
		b a c
		b c a
		c b a
		c a b
	*/

	// Permutations
	char arr[] = "abcd";

	RecurPermutations(arr, 0, 0);
	cout << endl;

	RecurPermutations(arr, 0, 1);
	cout << endl;

	RecurPermutations(arr, 0, 2);
	cout << endl;

	// RecurPermutations(arr, 0, 3);
	// cout << endl;

	return 0;
}
