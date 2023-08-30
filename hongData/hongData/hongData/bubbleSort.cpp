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

#pragma region ��Ʈ
/*
----------------------------------------------------------------------------------------------------

ū ���� �ڷ� ������ �����ϰ� ���� ū ���� �ڷ� ������ ���� ���� �����̴�
1��°�� ���� ū ���� �ڷ� ������ ���� ��ǥ�̰�
�׸��� �������� ū ���� �ڷ� ������ ���� ���� �����̴�

----------------------------------------------------------------------------------------------------

���� ���Ŀ��� ���� ������ �� �Ǿ� �ִٸ� 
swap�ϴ� ���� bool ������ true�� �ٲپ üũ�ϴ� ���� �ִ�
���� for���� üũ�� �ؼ� false�� braek�� �ɸ� �ȴ�.

*/
#pragma endregion
