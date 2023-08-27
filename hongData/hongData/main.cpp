//
//  main.cpp
//  hongData
//
//  Created by 신동주 on 2023/08/26.
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
//    이렇게 포인터롤 해도 되고 아니면 a앞에 *를 넣어 사용해도 된다.
//    temp = *a;
//}

//void intSwap(int &a,int &b)
//{
//    int temp;
//    temp = a;
//    a = b;
//    b= temp;
//    ref를 사용하면 앞에 포인터를 사용하지 않아도 되기 때문에 보기가 편하다그리고 함수에도 변수만 적으면 되서 좋다
//}

bool CheckSorted(int *arr,int size)
{
    if(arr[0] <= arr[1])
    {
        if(arr[1]<=arr[2])
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

void Change(int *arr, int size)
{
    for(int i=0 ; i< size; i++)
    {
        if(arr[0] <= arr[1])
        {
            if(arr[1]<=arr[2])
            {
                
            }
            else
            {
                int temp;
                temp = arr[1];
                arr[1] = arr[2];
                arr[2] =temp;
            }
        }
        else
        {
            int temp;
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] =temp;
            if(arr[1]<=arr[2])
            {
                
            }
            else
            {
                int temp;
                temp = arr[1];
                arr[1] = arr[2];
                arr[2] =temp;
            }
        }
    }
    
}

int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j =0;j<5;j++)
        {
            for(int k =0;k<5;k++)
            {
                int arr[3]={k,j,i};
                int size = sizeof(arr)/sizeof(arr[0]);
                
                for(int e= 0;e<size;e++)
                {
                    cout << arr[e] << " ";
                }
                
                cout << "->" << " ";
                
                Change(arr,size);
                
                for(int e = 0;e<size;e++)
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

//정렬(sorting)
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
