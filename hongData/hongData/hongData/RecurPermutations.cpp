#include <iostream>

using namespace std;

int a = 0;
int b = 0;
void Swap(char& left, char& right);

void RecurPermutations(char* arr, int left, int right)
{
	if (left == right)
	{
		for (int i = 0;i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = left; i <= right; i++)
		{
			Swap(arr[left], arr[i]);

			RecurPermutations(arr, left + 1, right);

			Swap(arr[left], arr[i]);

		}
	}
}

void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}

int main()
{
	char car[3] = { 'a', 'b', 'c' };
	int n = sizeof(car) / sizeof(car[0]);

	RecurPermutations(car, 0, n - 1);

	return 0;
}