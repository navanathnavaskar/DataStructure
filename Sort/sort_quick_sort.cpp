/*

QuickSort is a Divide and Conquer algorithm. 

It picks an element as pivot and 
partitions the given array around the picked pivot. 
There are many different versions of quickSort that pick pivot in different ways. 

1. Always pick first element as pivot.
2. Always pick last element as pivot (implemented below)
3. Pick a random element as pivot.
4. Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, 
given an array and an element x of array as pivot, put x at its correct 
position in sorted array and put all smaller elements (smaller than x) before x, 
and put all greater elements (greater than x) after x. 
All this should be done in linear time.

*/

#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j <= high-1;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[j], &a[i]);
        }
    }

    swap(&a[++i], &a[high]);
    return(i);
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}