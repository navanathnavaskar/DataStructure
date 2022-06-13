/*
Given an array of random numbers, Push all the zero’s of a given array to the end of the array. 

For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, 
it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. 
The order of all other elements should be same. 
Expected time complexity is O(n) and extra space is O(1).
*/

#include<iostream>
using namespace std;

void moveZeros(int a[], int n)
{
    int count = 0;

    for (int i = 0;i < n; i ++)
    {
        if (a[i] != 0)
        {
            a[count++] = a[i];
        }
    }

    while (count < n)
    {
        a[count++] = 0;
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
    int arr[] = {2,0,4,7,0,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    moveZeros(arr, n);
    printArray(arr, n);
    return 0;
}