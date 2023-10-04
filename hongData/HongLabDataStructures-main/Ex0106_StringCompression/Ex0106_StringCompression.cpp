#include <iostream>
#include <cassert>

using namespace std;

void InsertionSort(char* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) // <- while ���
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int Count(char* arr, int n, char x)
{
	int count = 0;
	for (int i = 0; i < n; i++) // start index ���
	{
		if (arr[i] == x)
			count++;
	}

	return count;
}

int main()
{
	// ����
	// - � ���ĺ��� �� �� ���������� ���
	// - ����) aaabbccdddeeeff -> a3b2c2d3e3f2
	// - ���ĺ��� �� 26 ����	

	// cout << int('a') << " " << int('z') << endl; // 97 122

	// char arr[] = "ababcdfdceeefda";
	// char arr[] = "a";
	char arr[] = "ababcdfdceeedag";
	int n = sizeof(arr) - 1; // ������ �Ⱥ��̴� '\0' ����

	// ���ڰ� �ϳ��̻��̶�� ����
	// ���ڰ� ������ if�� �ƿ� ������ ���ϵ��� ó�� ����
	assert(n >= 1);

	cout << arr << endl;

	// Ǯ�� 1. ��� ���ĺ��� ���ؼ� Count()
	// ��Ʈ: �ҹ��� ���ĺ� 'a'~'z'�� int�δ� 97~122�� ����
	// ����: ���� ���ĺ��� ���� �Ѵ�.

	// ǥ�� ����� ���� �ְ� ������� ���� ���� ����
	int table[26] = { 0 }; // ��� ���� 0���� �ʱ�ȭ

	for (int i = 0; i < 26; i++)
	{
		// ��Ʈ: char(i + 97)

		// ǥ�� ����� ���߿� ���Ƽ� ����ϴ� ���
		// table[i] = ...

		// ǥ�� ������ �ʰ� ���� ����ϴ� ���
		// ...
	}

	cout << endl;

	// ���
	for (int i = 0; i < 26; i++)
	{
		// ...
	}
	cout << endl << endl;

	// Ǯ�� 2. ���� �� ã��
	// ���⼭�� ������ ���ڿ��� ����� ���� �ƴ϶� ����� ��ǥ
	// Table�� ������ ����

	InsertionSort(arr, n);

	cout << arr << endl;

	char c = arr[0];
	int count = 1;

	cout << c;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == c)
		{
			// TODO: ...
		}
		else
		{
			// TODO: ...
		}
	}

	cout << count << endl; // ������ count ���

	return 0;
}
