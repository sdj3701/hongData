#include <iostream>
#include <iomanip> // setw

using namespace std;

int Fibonnacci(int n);
int RecurFibonnacci(int n);

int main()
{
	// Input      : 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377

	cout << "Input		: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << i << " ";
	cout << endl;

	cout << "Fibonnacci	: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << Fibonnacci(i) << " ";
	cout << endl;

	cout << "Fibonnacci : ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << RecurFibonnacci(i) << " ";
	cout << endl;

	return 0;
}

int Fibonnacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		int fn = 0;

		

		return fn;
	}
}

int RecurFibonnacci(int n)
{

	return 0;
}
