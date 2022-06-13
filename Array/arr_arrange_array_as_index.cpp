/*
Rearrange an array in maximum minimum form | Set 2 (O(1) extra space)

Given a sorted array of positive integers, rearrange the array alternately 
i.e first element should be the maximum value, second minimum value, third-second max, fourth-second min and so on. 
Examples:
    Input: arr[] = {1, 2, 3, 4, 5, 6, 7} 
    Output: arr[] = {7, 1, 6, 2, 5, 3, 4}
    Input: arr[] = {1, 2, 3, 4, 5, 6} 
    Output: arr[] = {6, 1, 5, 2, 4, 3} 
*/

#include<iostream>
using namespace std;

void arrangeArr(int a[], int n)
{
    int max = a[n-1];
    int min = a[0];
    for(int i = 0;i<n; i++)
    {
        if(i%2==0) //even number
        {
            a[i] = max;
            max -= 1;
        }
        else
        {
            a[i] = min;
            min += 1;
        }
    }
}

void printArray(int a[] , int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1, 2,3,4,5,6,7,8,9};

    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    arrangeArr(arr, n);
    printArray(arr, n);
    return 0;
}
