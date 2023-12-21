#include "../shared/Deque.h"

#include <iostream>

int main()
{
	// Double Ended Queue (��)
	Deque<char> d(8);

	d.SetDebugFlag(false);

	d.Print();

	d.PushFront('A');
	d.Print();

	d.PushFront('B');
	d.Print();

	d.PushBack('C');
	d.Print();

	d.PushBack('D');
	d.Print();

	d.PopFront();
	d.Print();

	d.PopBack();
	d.Print();

	return 0;
}

