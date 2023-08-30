#include <iostream>

using namespace std;

void Swap(int& a, int& b);
void Print(int* arr, int n);

int main()
{

	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int count = 0;
	bool check = false;

	//Bubble Sort
	{
		for (int i = 0; i < n - i ; i++)
		{
			for (int j = 0;j < n - 1 - i; j++) 
			{
				if (arr[j] > arr[j + 1])
					Swap(arr[j], arr[j + 1]);
			}
			Print(arr, n);
			
		}
	}

	return 0;
}

void Print(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

#pragma region 노트
/*
----------------------------------------------------------------------------------------------------

큰 값을 뒤로 보내서 저장하고 다음 큰 값을 뒤로 보내는 것이 버블 정렬이다
1번째는 가장 큰 값을 뒤로 보내는 것이 목표이고
그리고 다음으로 큰 수를 뒤로 보내는 것이 버블 정렬이다

----------------------------------------------------------------------------------------------------

버블 정렬에서 만약 정렬이 다 되어 있다면 
swap하는 곳에 bool 변수를 true로 바꾸어서 체크하는 법이 있다
밖의 for문에 체크를 해서 false면 braek를 걸면 된다.

*/
#pragma endregion
