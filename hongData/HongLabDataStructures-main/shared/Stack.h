#pragma once

#include <cassert>
#include <iostream>

template<typename T> // ���ø� ���
class Stack
{
public:
	Stack(int capacity = 1)
	{
		assert(capacity > 0);
		Resize(capacity);
	}

	~Stack()
	{
		if (stack_) delete[] stack_;
	}

	void Resize(int new_capacity)
	{
		T* new_stack = new T[new_capacity];
		memcpy(new_stack, stack_, sizeof(T) * Size());
		if (stack_) delete[] stack_;
		stack_ = new_stack;
		capacity_ = new_capacity;
	}
	 
	bool IsEmpty() const
	{
		return false; // TODO:
	}

	int Size() const
	{
		return capacity_; //TODO:
	}

	void Print()
	{
		using namespace std;

		for (int i = 0; i < Size(); i++) // Size() ���
			cout << stack_[i] << " ";
		cout << endl;
	}

	// Returns TOP element of stack.
	T& Top() const
	{
		assert(!IsEmpty());

		return stack_[capacity_ + top_ -1];
	}

	// Insert item into the TOP of the stack
	void Push(const T& item)
	{
		stack_[capacity_ - 1] = item;
		capacity_++;
		Resize(capacity_);

		// TODO: �ʿ��ϸ� �������� 

		// TODO:
	}

	// Delete the TOP element of the stack
	void Pop()
	{
		assert(!IsEmpty());

		// TODO:
	}

protected: // �ڿ��� ����ؼ� ���
	T* stack_ = nullptr;
	int top_ = -1; // 0 �ƴ�
	int capacity_ = 0;
};
