/*
Program to print array in zig zag manner.

    Input: arr[] = {4, 3, 7, 8, 6, 2, 1} 
    Output: arr[] = {3, 7, 4, 8, 2, 6, 1}

    Input: arr[] = {1, 4, 3, 2} 
    Output: arr[] = {1, 4, 2, 3}
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void zigzag(int a[], int n)
{
    sort(a, a+n);

    for(int i = 1; i<n-1; i=i+2)
    {
        swap(a[i], a[i+1]);
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
    int arr[] = {8,1,7,2,3,9,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    zigzag(arr, n);
    printArray(arr, n);
    return 0;
}