#include <iostream>

using namespace std;

void RecurFunc(int count)
{

	if (count == 0)
		return;

	RecurFunc(count - 1); // �̰ſ� 

	cout << count << endl;

	RecurFunc(count - 1); // �̰Ŵ� �ٸ���
}


int main()
{ 

	RecurFunc(5);

	return 0;
}