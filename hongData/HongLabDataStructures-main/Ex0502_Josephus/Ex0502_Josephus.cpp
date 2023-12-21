#include "../shared/Queue.h"

#include <iostream>

using namespace std;

int main()
{
	int n = 7, k = 3; // set n and k to the desired values

	Queue<int> q(n + 1);
	q.SetDebugFlag(false);

	// ó���� n�� �߰� (1, 2, ..., n)
	for (int i = 1; i <= n; i++)
		q.Enqueue(i);
	while (q.Size() > 1)
	{
		q.Print();

		for (int i = 0; i < k - 1; i++)
		{
			int temp = q.Front();
			q.Dequeue();
			q.Enqueue(temp);
		}
		q.Print();
		cout << "Executed " << q.Front() << endl;
		q.Dequeue();
	}
	
	cout << "Survior: " << q.Front() << endl;

	// ������ �� ���� ���� ������ �ݺ�
	{
		// k-1 ���� �� �տ��� �ڷ� ������

		// k ��° ��� ó��
		// cout << "Executed " << ... << endl;
	}

	// ������ ������ ��ȣ
	// cout << "Survivor: " << ... << endl;

	return 0;
}
// 