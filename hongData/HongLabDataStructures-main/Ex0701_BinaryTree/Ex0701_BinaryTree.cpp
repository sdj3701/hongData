#include <iostream>

#include "../shared/BinaryTree.h"

using namespace std;

/*
[���]
- ���� �ڷᱸ�� vs ���� �ڷᱸ��
- Ʈ��(tree), ����Ʈ��(subtree)
- ���(node), ��Ʈ(root) ���,
- �θ� ���, �ڽ� ���, ����(sibling) ���, ����(ancestor) ���, �ļ�(descendent) ���
- �ܸ� ���(terminal node, leaf node), ��ܸ� ���(nonterminal node)
- ����� ����(degree): �ڽ� ����� ����
- Ʈ���� ����: ������ ���� �� ���� ū ����
- ����(��Ʈ�� ������ 1), ����, ���� https://stackoverflow.com/questions/2603692/what-is-the-difference-between-tree-depth-and-height
- ����: �ִ� ����
- ����(edge)
- ���� Ʈ��: ��� ����� ������ 2 ���� (�ִ� 2���� �ڽ� ���)
- ��ȭ ���� Ʈ��(full binary tree): ��� ��尡 ���� �� �ִ� Ʈ��
- ���� ���� Ʈ��(complete binary tree): ������ ���� �ܿ��� ��� �� ���ְ� ������ ������ ���ʺ��� ���ִ� Ʈ�� (�߰� ��� X)
*/

int main()
{
	// �迭�ε� ���� ����

	using Node = BinaryTree<int>::Node;

	Node* n1 = new Node{ 1, nullptr, nullptr }; // �����ȣ �ʱⰪ ���� (������ �ƴ�)
	Node* n2 = new Node{ 2, n1, nullptr };
	Node* n3 = new Node{ 3, nullptr, nullptr };
	Node* n4 = new Node{ 4, nullptr, nullptr };
	Node* n5 = new Node{ 5, nullptr, n4 };
	Node* n6 = new Node{ 6, n2, n5 };

	n1->right = n3; // <- ������� ����

	BinaryTree<int> tree(n6); // <- n6�� �ּҸ� root node�� 

	tree.Print2D();

	cout << "Sum: " << tree.Sum() << endl;//Sum: 21
	cout << "Height: " << tree.Height() << endl;//Height : 4


	// Tree traversal methods

	cout << "Preorder" << endl; // 6 2 1 3 5 4
	tree.Preorder();
	cout << endl;

	cout << "Inorder" << endl; // 1 3 2 6 5 4
	tree.Inorder();
	cout << endl;

	cout << "Postorder" << endl; // 3 1 2 4 5 6
	tree.Postorder();
	cout << endl;

	cout << "LevelOrder" << endl; // 6 2 5 1 4 3
	tree.LevelOrder();
	cout << endl;

	cout << "Iterative Preorder" << endl; // 6 2 1 3 5 4
	tree.IterPreorder();
	cout << endl;

	cout << "Iterative Inorder" << endl; // 1 3 2 6 5 4
	tree.IterInorder();
	cout << endl;

	cout << "Iterative Postorder" << endl; // 3 1 2 4 5 6
	tree.IterPostorder();
	cout << endl;

	// Ʈ�� �Ҹ��ڿ��� ����
	//delete n1;
	//delete n2;
	//delete n3;
	//delete n4;
	//delete n5;
	//delete n6;

	return 0;
}
