/*
Program to reverse a given array
*/
#include<iostream>
using namespace std;

void reverse(int a[], int n)
{
    int l = 0;
    int r = n-1;

    while(l<r)
    {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

void printArray(int a[], int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

int main()
{
    int arr[] = {45,12,6,1,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    printArray(arr,n);
    return 0;   
}