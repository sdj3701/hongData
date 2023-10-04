#include <iostream>
#include <cassert> // assert()

using namespace std;

// ����
// - �迭�� ���鵵 �����̰� �ε����� ������ �򰥸��� ���� �翬�մϴ�. 
// - �ܱ� ���߷��� �ʿ��ѵ� �ͼ������ž� �մϴ�.

// �迭 arr�� x�� �� �� �������� ��ȯ
int Count(int* arr, int n, int x);

// �迭 arr�� x�� ������ index ��ȯ, ������ -1 ��ȯ
int SequentialSearch(int* arr, int n, int x); // LinearSearch

// ���ĵ� �迭���� x�� �� �� �������� ��ȯ
int SortedCount(int* arr, int n, int x);
int SortedCountHelper(int* arr, int n, int x, int start); // start ���

// ������ �� ���
void InsertionSort(int* arr, int n);

void Print(int* arr, int size);

int main()
{
	// ���ĵ��� ���� �����͸� ����

	int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 , 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// ������ �˰����̳� �ڷᱸ���� ������ ���� 
	// �Ǽ��� ���ɼ��� ���� �ܼ��� ����� �������� ��ƿ�.

	cout << "Count 9 = " << Count(arr, n, 9) << endl;
	cout << "Count 2 = " << Count(arr, n, 2) << endl;
	cout << "Count 8 = " << Count(arr, n, 8) << endl;
	cout << "Count 1 = " << Count(arr, n, 1) << endl;
	cout << endl;

	cout << "Search 2 = " << SequentialSearch(arr, n, 2) << endl;
	cout << "Search 5 = " << SequentialSearch(arr, n, 5) << endl;
	cout << "Search 9 = " << SequentialSearch(arr, n, 9) << endl;
	cout << endl;

	InsertionSort(arr, n);

	Print(arr, n);

	cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << endl;
	cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << endl;
	cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << endl;
	cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << endl;
	cout << endl;

	return 0;
}

// �迭 arr�� x�� �� �� �������� ��ȯ
int Count(int* arr, int n, int x)
{
	// TODO:

	return 0;
}

// �迭 arr�� x�� ������ index ��ȯ, ������ -1 ��ȯ
int SequentialSearch(int* arr, int n, int x)
{
	// TODO:

	return -1;
}

int SortedCountHelper(int* arr, int n, int x, int start) // start ���
{
	// TODO: 

	return 0;
}

int SortedCount(int* arr, int n, int x)
{
	int i = SequentialSearch(arr, n, x);

	if (i >= 0)
		return SortedCountHelper(arr, n, x, i + 1) + 1;
	else
		return 0;
}

void InsertionSort(int* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}