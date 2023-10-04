#include <iostream>

#include "../shared/Stack.h"
#include "../shared/Queue.h"
#include "../shared/BinaryTree.h"

using namespace std;

// Function to return precedence of operators
int Prec(char c);
void InfixToPostfix(Queue<char>& q, Queue<char>& output);
int EvalPostfix(Queue<char>& q);

class ExpressionTree : public BinaryTree<char>
{
public:
	typedef BinaryTree<char> Base;

	ExpressionTree(Node* root) : Base(root) {}

	bool IsDigit(char c)
	{
		if (c >= '0' && c <= '9') return true;
		else return false;
	}

	int Evaluate()
	{
		return Evaluate(Base::root_);
	}

	int Evaluate(Node* node)
	{
		// TODO: Ʈ���� ����� ������ ������� ���
		return 0;
	}

	void Infix() { Infix(root_); cout << endl; }
	void Infix(Node* node) {
		// TODO: ������ Infix �������� ��� (��ȣ ����)
	}

	void Postfix() { Postfix(root_);  cout << endl; }
	void Postfix(Node* node) {
		// TODO: ������ Postfix �������� ���
	}

	// Infix -> postfix -> expression tree
	ExpressionTree(const char* infix)
	{
		// Infix -> Postfix (���� ����)
		Queue<char> q;
		for (int i = 0; infix[i] != '\0'; i++)
			q.Enqueue(infix[i]);
		cout << "  Infix: ";
		q.Print();
		Queue<char> postfix;
		InfixToPostfix(q, postfix);
		cout << "Postfix: ";
		postfix.Print();

		// Postfix -> Expression tree

		Stack<Node*> s;

		while (!postfix.IsEmpty())
		{
			char c = postfix.Front();
			postfix.Dequeue();

			if (c >= '0' && c <= '9')
			{
				// TODO:
			}
			else
			{
				// TODO:
			}
		}

		root_ = s.Top();
	}
};

int main()
{
	using Node = ExpressionTree::Node;

	// 5 + (3 - 2) * 4
	// 
	//    +
	//	/   \
	// 5     *
	//	    / \
	//	   -   4
	//	  / \
	//	 3   2

	Node* n1 = new Node{ '5', nullptr, nullptr };
	Node* n2 = new Node{ '+', nullptr, nullptr };
	Node* n3 = new Node{ '3', nullptr, nullptr };
	Node* n4 = new Node{ '-', nullptr, nullptr };
	Node* n5 = new Node{ '2', nullptr, nullptr };
	Node* n6 = new Node{ '*', nullptr, nullptr };
	Node* n7 = new Node{ '4', nullptr, nullptr };

	// +
	n2->left = n1; // 5
	n2->right = n6; // *

	// *
	n6->left = n4; // -
	n6->right = n7; // 4

	// -
	n4->left = n3; // 3
	n4->right = n5; // 2

	ExpressionTree tree(n2);

	tree.Print2D();

	// ���� Ʈ���� ����Ǿ� �ִ� ������ ������ ����ؼ� �� ����� ����մϴ�.
	cout << "Evaluated = " << tree.Evaluate() << endl; // Evaluated = 9

	// ���� Ʈ���� ����Ǿ� �ִ� ������ Infix ������� ����մϴ�.
	cout << "  Infix: ";
	tree.Infix();   // (5+((3-2)*4)) <- ��� ����

	// ���� Ʈ���� ����Ǿ� �ִ� ������ Postfix ������� ����մϴ�.
	cout << "Postfix: ";
	tree.Postfix(); // 532-4*+ <- ��� ����

	cout << endl;

	// Infix -> Postfix -> Expression Tree
	{
		// const char infix[] = "1+(1*2+3)*4";
		const char infix[] = "(5+((3-2)*4))";

		// �����ڿ��� ���ڿ��� �Է¹��� ������ ���������� Infix->Postfix ������ ���� Ʈ���� �����մϴ�.
		ExpressionTree tree(infix);

		tree.Print2D();

		// ���� Ʈ���� ����Ǿ� �ִ� ������ ������ ����ؼ� �� ����� ����մϴ�.
		cout << "Evaluated = " << tree.Evaluate() << endl; // Evaluated = 9
	}

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
		return -1; // '('�� �켱������ ���� ���� ������ ó��
}

void InfixToPostfix(Queue<char>& q, Queue<char>& output)
{
	Stack<char> s; // �켱������ ���� ������ �����ϱ� ���� ����

	output.SetDebugFlag(false);

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		//cout << c << endl;

		if (c >= '0' && c <= '9') // ����(�ǿ�����)��� output�� �߰�
			output.Enqueue(c);
		else if (c == '(') // ���� ��ȣ��� ���ÿ� �߰�
			s.Push(c);
		else if (c == ')') // �ݴ� ��ȣ�� ������
		{
			// ���� ��ȣ �������� ���ÿ��� ������ ��¿� �ֱ�
			while (s.Top() != '(')
			{
				output.Enqueue(s.Top());
				s.Pop();
			}
			s.Pop(); // ���� ��ȣ ����
		}
		else // �����ڸ� ������
		{
			// ���ÿ��� c���� �켱������ ���ų� ���� �͵��� ������ �߰�
			while (!s.IsEmpty() && Prec(c) <= Prec(s.Top()))
			{
				output.Enqueue(s.Top());
				s.Pop();
			}

			// c�� ���ÿ� �߰�
			s.Push(c);
		}

		//cout << "Stack: ";
		//s.Print();
		//cout << "Output:";
		//output.Print();
		//cout << endl;
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

		//cout << c << endl;

		if (c != '+' && c != '-' && c != '*' && c != '/')
		{
			s.Push(c - '0'); // �Է��� �����ڰ� �ƴϸ� �ϴ� ����
		}
		else
		{
			//cout << "Operator: " << c << endl;

			// �Է��� �������̸� ���ÿ��� ������ ���꿡 ���
			int op2 = s.Top(); // op1, op2 ���� ����
			s.Pop();
			int op1 = s.Top();
			s.Pop();

			if (c == '+') {
				s.Push(op1 + op2);
			}
			else if (c == '-') {
				s.Push(op1 - op2);
			}
			else if (c == '*') {
				s.Push(op1 * op2);
			}
			else if (c == '/')
			{
				s.Push(op1 / op2);
			}
			else
			{
				cout << "Wrong operator" << endl;
				exit(-1); // ���� ����
			}
		}

		//cout << "Stack: ";
		//s.Print();
	}

	return s.Top();
}
