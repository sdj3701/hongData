#include <iostream>

using namespace std;

void Print(int* arr, int n);
void Swap(int& a, int b);

int main()
{

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