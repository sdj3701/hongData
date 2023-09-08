#include <iostream>

using namespace std;

void BinarySearch(int* arr, int size, int num);

int main()
{
	//int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr[] = { 2,4,5,5,6,8,9,10,12,13 };
	int n = sizeof(arr) / sizeof(arr[0]);

	BinarySearch(arr,n,5);

	return 0;
}

void BinarySearch(int* arr, int size, int num)
{
	int left = 0;
	int right = size - 1;
	int middle = 0;
	int start = 0;

	while (1)
	{
		cout << "Indices: ";
		for (int i = left; i < size;i++)
		{
			cout << i << " ";
		}
		cout << endl;
		cout << "Values : ";
		for (int i = left;i < size;i++)
		{
			cout << arr[i] << " ";
			if (arr[i] == num)
			{
				start = i;
			}
		}
		cout << endl;
		
		middle = (left + right) / 2;
		cout << "middle " << middle << endl;

		if (start == middle)
		{
			cout << "Found " << num << endl;
			break;
		}

		if (middle > start)
		{
			right = middle - 1;
			size = -1 * (left - right) + 1;
			cout << "right " << right << endl;
			if (left > right)
			{
				cout << "Not Found" << endl;
				break;
			}
		}
		else
		{
			left = middle + 1;
			cout << "left " << left << endl;
			if (left > right)
			{
				cout << "Not Found" << endl;
				break;
			}
		}
	}
}

