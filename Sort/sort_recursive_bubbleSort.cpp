#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

void bubbleSort(int a[], int n)
{
    if (n == 1)
        return;

    for(int j = 0; j < n-1; j++)
    {
        if(a[j+1] < a[j])
        {
            swap(&a[j+1], &a[j]);
        }
    }

    bubbleSort(a, n-1);
}

int main()
{
    int arr[] = {84,65,62,28,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}