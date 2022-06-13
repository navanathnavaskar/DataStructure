/*
Let the array be arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7
A = [1, 2] and B = [3, 4, 5, 6, 7]


    Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
    Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
    Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]
*/
#include <iostream>
using namespace std;
void reverseArray(int a[], int start, int end)
{
    while(start<end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void leftRotateArray(int a[], int n, int d)
{
    reverseArray(a, 0, d-1);
    reverseArray(a, d, n-1);
    reverseArray(a, 0, n-1);
}

void printArray(int a[], int n)
{
    for (int j = 0; j < n; j++)
    {
        cout<<a[j]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {111,112,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    leftRotateArray(arr, n, 2);
}
