/*
Move all negative numbers at begining and positive numbers at end.

Example:
Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
*/

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void rearrange(int a[], int n)
{
    int high = n-1;
    int low = 0;

    while(low<high)
    {
        if(a[low] < 0)
        {
            low++;
        }
        else if(a[high] > 0)
        {
            high--;
        }
        else
        {
            swap(a[low], a[high]);
        }
    }
}

void printArray(int a[], int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

int main()
{
    int arr[] = {-1,23,2,-2,7,-4,-5,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}