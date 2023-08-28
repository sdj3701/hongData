#include <iostream>

using namespace std;

void Print(int *arr,int size);
void Swap(int &i, int &j);

int main()
{
    
    //���� ���� �� ã��
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

    //���� ���� ���� �ε��� ã��
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

#pragma region ��Ʈ
/*
--------------------------------------------------------------------------------------------------------------

Swap()�Լ� ���� int Swap()�Լ� ������ ��ȯ �ϴµ��� ������� �ִ�
return �⺻������ �ϳ��� ���� ��ȯ �ϴµ� �ڸ��� swap�ҷ��� ���� 2�� ��ȯ �ؾ��ϴ� ������ �ִ�.

�̸� �ذ� �ϱ� ���ؼ� C/C++ ����� �ΰ��� �ִ�

1. C ���
void Swap(int *i,int *j)
�����ͷ� �ּҿ� ������ �ؼ� ���� �����ϴ� ����� �ִ�.
�����ͷ� ������ �ϸ� temp�� �����ͷ� ���� �ؼ� ���� �ٲ�� �ϰ�
�Լ��� main���� ���� �Ҷ��� �ּҷ� ������ �ؾ� �ϹǷ� ������ ��ٷӴ�.

2. C++ ���
void Swap0(int& i,int& j)
���۷����� ������ �ؼ� ���� �����ϴ� ����̴�.
�̴� C ��� ���� ����ϱⰡ ���ϴ�.
�Լ��ȿ� �ִ� temp�� �׳� �����ؼ� ����ϸ� �ǰ� 
mian������ ������ �� �׳� ���� ����ϸ� �ȴٶ�� ������ �ִ�.

--------------------------------------------------------------------------------------------------------------

Selection Sort
�ڸ��� �ٲٴ� �����̴�
�ϴ� ���� ���������� �����Ͽ� ���� ���� ���� ã�� ���� ���� ������ �ϰ�


--------------------------------------------------------------------------------------------------------------


*/
#pragma endregion

