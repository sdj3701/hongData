#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// ����: prev/next�� �ƴ϶� left/right
	};

	DoublyLinkedList()
	{
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // ��� ������(delete) �մϴ�.
	{
		// TODO:
	}

	bool IsEmpty()
	{
		return true; // TODO:
	}

	int Size()
	{
		int size = 0;

		// TODO:

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
			cout << endl;

			cout << "Backward: ";
			// TODO:
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		return nullptr; // TODO:
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
		}
	}

	void PushFront(T item)
	{
		// TODO:
	}

	void PushBack(T item)
	{
		// TODO:
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO:
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// �� �ڿ��� �ϳ� ���� ��带 ã�ƾ� �մϴ�.

		assert(first_);

		// TODO:
	}

	void Reverse()
	{
		// TODO:
	}

	T Front()
	{
		assert(first_);

		return T(); // TODO:
	}

	T Back()
	{
		assert(first_);

		return T(); // TODO:
	}

protected:
	Node* first_ = nullptr;
};