#include <iostream>

using namespace std;

void NoSort(char* arr, int size);

int main()
{
	//어떤 알파벳에 몇 번 나오는지로 출력 순서대로
	char arr[] = "zzzxxxaabbyyxxxaabbyyababcdfdceeedag";
	int n = sizeof(arr) - 1;

	cout << arr << endl;

	for (int i = 1; i < n;i++)
	{
		int key = arr[i];
		int j = i;
		for (;j > 0 && arr[j - 1] > key;j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = key;
	}
	
	char c = arr[0];
	int count = 1;

	for (int i = 1; i < n;i++)
	{
		if (arr[i] == c)
		{

		}
		else
		{

		}
	}

	cout << count << endl;

	return 0;
}

void NoSort(char* arr, int size)
{
	int count = 0;
	for (int i = 0; i < 26; i++)
	{
		count = 0;
		for (int j = 0; j < size;j++)
		{
			if (i + 97 == arr[j])
				count++;
		}
		char a = i + 97;
		if (count != 0)
			cout << a << count;
	}
}