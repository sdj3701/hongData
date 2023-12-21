#include <iostream>

#include "../shared/Stack.h"
#include "../shared/Queue.h"

using namespace std;

int Prec(char c); // ������ �켱������ ��ȯ
void InfixToPostfix(Queue<char>& q, Queue<char>& output);
int EvalPostfix(Queue<char>& q);

/*
   infix: A/B-C+D*E-A*C
 postfix: AB/C-DE*+AC*-

   infix: 8 / 2 - 3 + 4 * 5 - 1 * 2 = 19
 postfix: 8 2 / 3 - 4 5 * + 1 2 * - // �����ڸ� ���������� ����
		  = 4 3 - 4 5 * + 1 2 * -
		  = 1 4 5 * + 1 2 * -
		  = 1 20 + 1 2 * -
		  = 21 1 2 * -
		  = 21 2 -
		  = 19
*/

int main()
{
	// ���������� ��ĭ ���� �� �ڸ� ���ڸ� ����

	//const char infix[] = "8/2+(3+4)*5-1*2";
	const char infix[] = "1+(1*2+3)*4";
	//const char infix[] = "1+2*3+3";
	//const char infix[] = "1+2*(3+1)";
	const int size = sizeof(infix) / sizeof(char) - 1;

	// ť�� ��� �ֱ�
	Queue<char> q;
	for (int i = 0; i < size; i++)
		q.Enqueue(infix[i]);

	Queue<char> postfix;

	cout << "Infix: ";
	q.Print();
	cout << endl;

	InfixToPostfix(q, postfix);

	cout << "Postfix: ";
	postfix.Print();

	cout << "Evaluated = " << EvalPostfix(postfix) << endl;

	return 0;
}

// Function to return precedence of operators
int Prec(char c)
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1; // '('�� �켱������ ���� ���� ������ ó��, ')' �ݴ� ��ȣ�� ���������� ���ܵα� ����
}

void InfixToPostfix(Queue<char>& q, Queue<char>& output)
{
	Stack<char> s; // �켱������ ���� ������ �����ϱ� ���� ����

	output.SetDebugFlag(false);

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		cout << c << endl;

		/*
		if (c >= '0' && c <= '9') // ����(�ǿ�����)��� output�� �߰�
			...;
		else if (c == '(') // ���� ��ȣ��� ���ÿ� �߰�
			...;
		else if (c == ')') // �ݴ� ��ȣ�� ������
		{
			// ���� ��ȣ �������� ���ÿ��� ������ ��¿� �ֱ�
			// ���� ��ȣ ����
		}
		else // �����ڸ� ������
		{
			// ���ÿ��� c���� �켱������ ���ų� ���� �͵��� ������ �߰�
			// c�� ���ÿ� �߰�
		}
		*/

		cout << "Stack: ";
		s.Print();
		cout << "Output:";
		output.Print();
		cout << endl;
	}

	// ���ÿ� �����ִ� �͵��� ��� �߰�
	while (!s.IsEmpty())
	{
		output.Enqueue(s.Top());
		s.Pop();
	}
}

int EvalPostfix(Queue<char>& q)
{
	Stack<int> s;

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		cout << c << endl;

		/*
		if (c != '+' && c != '-' && c != '*' && c != '/')
		{
			// �Է��� �����ڰ� �ƴϸ� �ϴ� ����
			// ���ڸ� ���ڷ� ��ȯ c - '0' ��: int('9' - '0') -> ���� 9
		}
		else
		{
			cout << "Operator: " << c << endl;

			// �Է��� �������̸� ���ÿ��� ������ ���꿡 ���

			if (c == '+') {
				...
			}
			else if (c == '-') {
				...
			}
			else if (c == '*') {
				...
			}
			else if (c == '/')
			{
				...
			}
			else
			{
				cout << "Wrong operator" << endl;
				exit(-1); // ���� ����
			}
		}
		*/

		cout << "Stack: ";
		s.Print();
	}

	return s.Top();
}
