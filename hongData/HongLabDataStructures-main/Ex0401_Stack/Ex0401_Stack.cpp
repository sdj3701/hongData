#include <iostream>

#include "../shared/Stack.h" // ��� "shared" ����

int main()
{
	using namespace std;

	// ������ ����(bag), �����̳�(container)
	// LIFO(Last-In-First-Out)

	Stack<char> s;

	s.Push('A');
	s.Print();

	s.Push('B');
	s.Print();

	s.Push('C');
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();
	s.Print();

	s.Push('E');
	s.Print();

	s.Pop();
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();

	// cout << "Top = " << s.Top() << endl; // ����� �� Top() �Ұ�

	// �ٸ� �ڷ����� stack�� ���� ���� �� �־��.
	{
		//Stack<int> int_stack;
		//int_stack.Push(123);
		//cout << int_stack.Top() << endl;
		//int_stack.Top();
	}

	// ���ڿ� ���� ����� ����ϱ� (���� ����ϱ� ����)
	{
		//const char str[] = "Hello, World!";
		//const int size = sizeof(str) - 1; // ������ '\0' ����

		//cout << "Input: " << str << endl;

		//Stack<char> stack;

		//// TODO:

		//cout << endl;
	}

	return 0;
}
