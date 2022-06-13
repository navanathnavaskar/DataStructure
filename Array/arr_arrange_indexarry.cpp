/*
Reorder an array according to given indexes

Given two integer arrays of same size, “arr[]” and “index[]”, 
reorder elements in “arr[]” according to given index array. 
It is not allowed to given array arr’s length.
*/
#include<iostream>
using namespace std;

void arrangeArr(int a[], int index[], int n)
{
    int temp[n];
    for(int i = 0; i < n; i++)
    {
        temp[index[i]] = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        a[i] = temp[i];
        index[i] = i;
    }
}

void printArray(int a[], int n)
{
    for(int i = 0; i<n;i++)
    {
        cout<<"\t"<<a[i];       
    }
    cout<<endl;
}

int main()
{
    int arr[] = {11,10,13,54};
    int index[] = {2,0,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    arrangeArr(arr, index, n);
    printArray(arr, n);
    printArray(index, n);
    return 0;
}