#include <iostream>

using namespace std;

int Count(int* arr, int size, int num);
int SequentialSeratch(int* arr, int size, int num);
int SortedCountHelper(int* arr, int size, int  x, int start);
int SortedCount(int* arr, int size, int x);
void Print(int* arr, int size);

int main()
{

	int arr[] = { 8,1,1,3,2,5,1,2,1,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Count 9 = " << Count(arr, n, 1) << endl;

	cout << "Count 2 = " << SequentialSeratch(arr, n, 9) << endl;

	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > key; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = key;
	}
	Print(arr, n);

	cout << "Count 2 = " << SortedCount(arr, n, 1) << endl;


	return 0;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int Count(int* arr, int size, int num)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			count++;
	}

	return count;
}

int SequentialSeratch(int* arr, int size, int num)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			return i;
		else
			count++;
	}
	if(count ==size)
		return -1;
}

int SortedCountHelper(int* arr, int size, int x, int start)
{
	int count = 0;
	for (int i = start; i < size; i++)
	{
		if (arr[i] == x)
			count++;
		else
			break;
	}
	return count;
}

int SortedCount(int* arr, int size, int x)
{
	//정렬을 하고나서 인덱스를 찾는다?
	//
	int i = SequentialSeratch(arr, size, x);

	if (i >= 0)
		return SortedCountHelper(arr, size, x, i + 1) + 1;
	else
		return 0;
}
