#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: ���� ����Ʈ ����
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // ��� ������(delete) �մϴ�.
	{
		// TODO: ��� ����
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size�� �ϳ��ϳ� ��� ��ȯ

		return size;
	}

	T Front()
	{
		assert(first_);

		return T(); // TODO: ����
	}

	T Back()
	{
		assert(first_);

		return T(); // TODO: ����
	}

	Node* Find(T item)
	{
		// TODO: item�� ������ ��� ������ ��ȯ

		return nullptr;
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			// TODO:
		}
		else
		{
			// TODO:
		}
	}

	void Remove(Node* n)
	{
		assert(first_);

		// �ϳ� ���� ��带 ã�ƾ� �մϴ�.
		// TODO:
	}

	void PushFront(T item)
	{
		// first_�� nullptr�� ���� �ƴ� ��� ������ �����غ��� (�ᱹ�� �� ��츦 �ϳ��� ��ĥ �� ����)

		// ���ο� ��� �����
		// TODO:

		// ���� ���� ����
		// TODO:
	}

	void PushBack(T item)
	{
		if (first_)
		{
			// TODO:
		}
		else
		{
			// TODO:
		}
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

		// TODO: �޸� ����
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

		// TODO: �޸� ����
	}

	void Reverse()
	{
		// TODO: 
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// �ּҸ� ª�� ������ ��� (�� �κ��� ��κ� �����ϱ⶧���� �޺κи� ���)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};