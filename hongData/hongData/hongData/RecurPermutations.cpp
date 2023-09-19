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
		Swap(arr[left + b], arr[left]);
		while (left != right - a)
		{
			for (int i = left; i <= right;i++)
				cout << arr[i] << " ";
			cout << endl;
			Swap(arr[right - a], arr[right]);
			a++;
		}
		a = 0;
		b++;
		RecurPermutations(arr, left + b, right);
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