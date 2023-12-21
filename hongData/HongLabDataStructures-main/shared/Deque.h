#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (��, dequeue�� ����)
template<typename T>
class Deque : public Queue<T>
{

	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T& Front()
	{
		return Base::Front();
	}

	T& Back()
	{
		return Base::Rear();
	}

	void PushFront(const T& item)
	{
		if (Base::IsFull())
			Base::Resize();
		// TODO: ���� �տ� ���� �־������
		if (Base::front_ != 0)
		{
			for (int i = Base::front_; i > 0; i--)
				Base::queue_[i + 1] = Base::queue_[i];
			Base::front_++;
		}
		else
		{
			Base::queue_[0] = item;
			Base::front_++;
		}
	}

	void PushBack(const T& item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());

		// TODO:
	}

private:
	// Queue�� ����
};
