//
//  main.cpp
//  hongData
//
//  Created by �ŵ��� on 2023/08/26.
//

#include <iostream>

using namespace std;

//int intSwap(int _a, int _b)
//{
//    int temp;
//    temp = _a;
//    _a = _b;
//    _b = temp;
//
//    return intSwap(_a,_b);
//}

//void intSwap(int *a,int *b)
//{
//    int* temp;
//    temp = a;
//    a = b;
//    b= temp;
//    �̷��� �����ͷ� �ص� �ǰ� �ƴϸ� a�տ� *�� �־� ����ص� �ȴ�.
//    temp = *a;
//}

//void intSwap(int &a,int &b)
//{
//    int temp;
//    temp = a;
//    a = b;
//    b= temp;
//    ref�� ����ϸ� �տ� �����͸� ������� �ʾƵ� �Ǳ� ������ ���Ⱑ ���ϴٱ׸��� �Լ����� ������ ������ �Ǽ� ����
//}

bool CheckSorted(int* arr, int size)
{
    if (arr[0] <= arr[1])
    {
        if (arr[1] <= arr[2])
        {
            cout << "true";
            return true;
        }
        else
        {
            cout << "false";
            return false;
        }
    }
    else
    {
        cout << "false";
        return false;
    }

}

void Change(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[0] <= arr[1])
        {
            if (arr[1] <= arr[2])
            {

            }
            else
            {
                int temp;
                temp = arr[1];
                arr[1] = arr[2];
                arr[2] = temp;
            }
        }
        else
        {
            int temp;
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
            if (arr[1] <= arr[2])
            {

            }
            else
            {
                int temp;
                temp = arr[1];
                arr[1] = arr[2];
                arr[2] = temp;
            }
        }
    }

}

int main()
{
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 5;j++)
        {
            for (int k = 0;k < 5;k++)
            {
                int arr[3] = { k,j,i };
                int size = sizeof(arr) / sizeof(arr[0]);

                for (int e = 0;e < size;e++)
                {
                    cout << arr[e] << " ";
                }

                cout << "->" << " ";

                Change(arr, size);

                for (int e = 0;e < size;e++)
                {
                    cout << arr[e] << " ";
                }

                CheckSorted(arr, size);
                cout << endl;
            }
        }
    }
    return 0;
}

//����(sorting)
//{
//    int arr1[5];
//    int arr2[5];
//    for(int i=0;i<5;i++)
//    {
//        for(int j=0;j<5;j++)
//        {
//            arr1[j] = j;
//            arr2[i] = i;
//
//            if(arr1[j]>arr2[i])
//                intSwap(arr1[j],arr2[i]);
//
//            cout << arr1[j] << " "<<arr2[i] << " ";
//            if(arr1[j] <=arr2[i])
//                cout << "true" << endl;
//            else
//                cout << "false" << endl;
//        }
//    }
//}
//    int a = 3;
//    int b = 2;

    //swap
    //{
        //cout << a << " " << b << endl;

        //intSwap(a,b);

        //cout << a << " " << b << endl;
    //}
