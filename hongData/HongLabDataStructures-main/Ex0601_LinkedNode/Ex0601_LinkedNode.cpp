#include <iostream>

using namespace std;

struct Node
{
	int item = 0;	  // <- ū �����͵� ����
	Node* next = nullptr;

	friend ostream& operator<<(ostream& os, const Node& n)
	{
		cout << n.item << " " << flush;
		return os;
	}
};

void RecurPrint(Node* node)
{
	// TODO:
}

void IterPrint(Node* node)
{
	// TODO:
}

int main()
{
	// ListArray�� ��

	Node* first = nullptr;
	first = new Node;
	first->item = 1;
	first->next = nullptr;

	Node* second = nullptr;
	second = new Node;
	second->item = 2;
	second->next = nullptr;

	Node* third = nullptr;
	third = new Node;
	third->item = 3;
	third->next = nullptr;

	Node* fourth = nullptr;
	fourth = new Node;
	fourth->item = 4;
	fourth->next = nullptr;

	Node* fifth = nullptr;
	fifth = new Node;
	fifth->item = 5;
	fifth->next = nullptr;

	// ��� �߰� ����

	cout << *first << endl;
	cout << *second << endl;
	cout << *third << endl;
	cout << *fourth << endl;
	cout << *fifth << endl;
	cout << endl;

	// ���� ���� ����� �ֱ�
	// first->next = second;
	// TODO:
	// ������

	//cout << *(first) << endl;
	//cout << *(first->next) << endl;
	//cout << *(first->next->next) << endl;
	//cout << *(first->next->next->next) << endl;
	//cout << *(first->next->next->next->next) << endl;
	//// cout << *(first->next->next->next->next->next) << endl; // ����

	cout << endl;

	// �ӽ� ���� ���
	//{
	//	Node* current = first;
	//	cout << *current << endl;

	// TODO:
	//	cout << endl;
	//}

	// ��� ȣ�� �̿�
	//RecurPrint(first);
	//cout << endl;

	// �ݺ��� �̿�
	//IterPrint(first);
	//cout << endl;

	// TODO: ������ ����

	return 0;
}
