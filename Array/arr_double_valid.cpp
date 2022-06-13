/*
Double the first element and move zero to end

For a given array of n integers and assume that ‘0’ is an invalid number and all others as a valid number. 
Convert the array in such a way that if both current and next element is valid and both have same value then 
double current value and replace the next number with 0. 
After the modification, rearrange the array such that all 0’s shifted to the end. 
Examples: 

Input : arr[] = {2, 2, 0, 4, 0, 8}
Output : 4 4 8 0 0 0
*/
#include<iostream>
using namespace std;

void moveZeroToEnd(int a[], int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] !=0)
        {
            a[count++] = a[i];
        }
    }
    while(count<n)
    {
        a[count++] = 0;
    }
}

void arrangeArr(int a[], int n)
{
    if (n < 2)
        return;

    for(int i = 0; i < n-1; i++)
    {
        if(a[i] != 0 && a[i] == a[i+1])
        {
            a[i] = 2*a[i];
            a[i+1] = 0;
        }
    }
    moveZeroToEnd(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i<n;i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

int main()
{
    int arr[] = {0,2,2,0,4,4,0,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    arrangeArr(arr, n);
    printArray(arr,n);
    return 0;
}