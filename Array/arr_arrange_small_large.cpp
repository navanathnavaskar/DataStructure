/*
Rearrange an array in order – smallest, largest, 2nd smallest, 2nd largest, ..

Input : arr[] = [5, 8, 1, 4, 2, 9, 3, 7, 6]
Output :arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5}

Sort array, then create temp array, copy element from start at first then from end at second 
and so on.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void arrangeArr(int a[], int n)
{
    sort(a, a+n);

    int l = 0;
    int r = n-1;
    int tempArr[n];
    int tempInx = 0;
    for (l = 0, r = n-1; l<n/2 || r>n/2;l++, r--)
    {
        tempArr[tempInx++] = a[l];
        tempArr[tempInx++] = a[r];
    }

    //change original array
    for(int i = 0;i<n;i++)
    {
        a[i] = tempArr[i];
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    arrangeArr(arr, n);

    for(int j = 0; j<n; j++)
    {
        cout<<"\t"<<arr[j];
    }
    return 0;
}