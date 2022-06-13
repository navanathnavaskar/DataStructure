/*
Rearrange array such that arr[i] >= arr[j] if i is even and arr[i]<=arr[j] if i is odd and j < i

Given an array of n elements. Our task is to write a program to rearrange the array such that elements at even positions are greater than all elements before it and elements at odd positions are less than all elements before it.
Examples: 
 

Input : arr[] = {1, 2, 3, 4, 5, 6, 7}
Output : 4 5 3 6 2 7 1

Input : arr[] = {1, 2, 1, 4, 5, 6, 8, 8} 
Output : 4 5 2 6 1 8 1 8

Approach:
----------
1. Copy the array into other array
2. Sort it
3. Point l to 0 and r to n-1
4. start from end of array1, if even position then add element from left else from right
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void arrangeArray(int a[], int n)
{
    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i] = a[i];
    }

    sort(b, b+n);

    int l = 0, r = n-1;

    for(int i = n-1;i>=0;i--)
    {
        if(i%2 == 0) //even pos
        {
            a[i] = b[l++];
        }
        else
        {
            a[i] = b[r--];
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i<n-1;i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    arrangeArray(arr, n);
    printArray(arr,n);
    return 0;
}