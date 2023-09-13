#include <iostream>

using namespace std;

int Sum(int* arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];

	return sum;
}

int RecurSum(int* arr, int size)
{
	if (size == 0)
		return 0;
	int sum = arr[size - 1];
	sum += RecurSum(arr, size - 1);

	return sum;
}


int main()
{

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << Sum(arr, n) << endl;
	cout << RecurSum(arr, n) << endl;

	return 0;
}