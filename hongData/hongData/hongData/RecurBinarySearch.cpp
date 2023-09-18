#include <iostream>

using namespace std;

int RecurBinarySearch(int* arr, int left, int right, int x)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < arr[middle])
		{
			return RecurBinarySearch(arr, left, middle - 1, x);
		}
		else if (x > arr[middle])
		{
			return RecurBinarySearch(arr, middle + 1, right, x);
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << RecurBinarySearch(arr, 0, n - 1, -2) << endl;

	return 0;
}

