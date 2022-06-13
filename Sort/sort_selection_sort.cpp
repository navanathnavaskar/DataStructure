/*
Selection Sort
Difficulty Level : Easy

The selection sort algorithm sorts an array by repeatedly finding the minimum element 
(considering ascending order) from unsorted part and putting it at the beginning. 
The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) 
from the unsorted subarray is picked and moved to the sorted subarray. 
Following example explains the above steps:
arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64 
*/

#include<iostream>
using namespace std;

void printArray(int a[], int n)
{
    for(int j = 0; j < n; j++ )
    {
        cout<<"\t"<<a[j];
    }
    cout<<endl;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int a[], int n)
{
    int minidx = 0;
    int i,j; 
    for(i = 0; i<n;i++)
    {
        minidx = i;
        for(j = i + 1; j < n;j++)
        {
            if(a[j] < a[minidx])
            {
                minidx = j;
            }
        }

        swap(&a[i], &a[minidx]);
    }
}

int main()
{
    int arr[] = {84,12,65,10,28};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}