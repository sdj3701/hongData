#include <iostream>

using namespace std;

void Print(int *arr,int size);
void Swap(int &i, int &j);

int main()
{
    
    //가장 작은 수 찾기
    {
        int arr[] = { 8,3,2,5,1,1,2,5,8,9 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int min = arr[0];

        for (int i = 0;i < size-1;i++)
        {
            if (!(min <= arr[i]))
            {
                min = arr[i];
            }
        }
        cout << min << endl;
    } 

    //가장 작은 수의 인덱스 찾기
    {
        int arr[] = { 8,3,2,5,4,1,2,5,8,9 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int min=0;

        for (int i = 0;i < size;i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        cout << arr[min] << endl;
    }

    //selection sort
    {
        int arr[] = { 8,3,2,5,1,1,2,5,8,9 };
        int size = sizeof(arr) / sizeof(arr[0]);

        int min_index;
        for (int i = 0;i < size - 1;i++)
        {
            min_index = i;
            Print(arr, size);
            for (int j = i + 1;j < size;j++)
            {
                if (arr[min_index] > arr[j])
                {
                    min_index = j;
                }
            }
            if (arr[i] > arr[min_index])
            {
                Swap(arr[i], arr[min_index]);
            }
        }

    }

    return 0;
}
void Print(int *arr, int size)
{
    for (int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
    return;
}

#pragma region 노트
/*
--------------------------------------------------------------------------------------------------------------

Swap()함수 만약 int Swap()함수 였으면 반환 하는데에 어려움이 있다
return 기본적으로 하나만 값을 반환 하는데 자리를 swap할려면 값을 2개 반환 해야하는 문제가 있다.

이를 해결 하기 위해서 C/C++ 방법이 두가지 있다

1. C 방법
void Swap(int *i,int *j)
포인터로 주소에 접근을 해서 값을 변경하는 방법이 있다.
포인터로 접근을 하면 temp도 포인터로 선언 해서 값을 바꿔야 하고
함수를 main에서 접근 할때도 주소로 접근을 해야 하므로 접근이 까다롭다.

2. C++ 방법
void Swap0(int& i,int& j)
레퍼런스로 접근을 해서 값을 변경하는 방법이다.
이는 C 방법 보다 사용하기가 편하다.
함수안에 있는 temp도 그냥 선언해서 사용하면 되고 
mian에서도 접근할 때 그냥 값을 사용하면 된다라는 장점이 있다.

--------------------------------------------------------------------------------------------------------------

Selection Sort
자리를 바꾸는 정렬이다
일단 값을 순차적으로 접근하여 가장 작은 값을 찾아 값을 따로 저장을 하고


--------------------------------------------------------------------------------------------------------------


*/
#pragma endregion

