#include <iostream>

using namespace std;

void Print(int* arr, int n);
void Swap(int& a, int& b);

int main()
{
	{
		int arr[] = { 6,5,4,3,2,1 };
		int n = sizeof(arr) / sizeof(arr[0]);

		Print(arr, n);

		int i = 4;

		for (int i = 1; i < n;i++)
		{
			int key = arr[i];
			int j = i;
			for (;j > 0 && arr[j - 1] > key;j--)
			{
				arr[j] = arr[j - 1];
				Print(arr, n);
			}
			arr[j] = key;
		}

		Print(arr, n);
		cout << endl;

	}

}

void Print(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


#pragma region 노트
/*

	삽입 정렬
	값을 저장하는 것
	중간에 for문 탈출



*/
#pragma endregion
