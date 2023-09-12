#include <iostream>

using namespace std;

void RecurFunc(int count)
{

	if (count == 0)
		return;

	RecurFunc(count - 1); // 이거와 

	cout << count << endl;

	RecurFunc(count - 1); // 이거는 다르다
}


int main()
{ 

	RecurFunc(5);

	return 0;
}