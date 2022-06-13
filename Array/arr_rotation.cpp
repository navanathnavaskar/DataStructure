// Program For array Rotation to left by n
//function will rotation 1 element to left.
//T - O(n)
//S - O(n)

#include <iostream>
using namespace std;

void leftRotateByOne(int a[], int n)
{
    int temp = a[0];
    for(int j = 0; j < n-1; j++)
    {
        a[j] = a[j+1];
    }
    a[n-1] = temp;
}

void leftRotateArray(int a[], int n, int d)
{
    for(int k = 0;k<d;k++)
    {
        leftRotateByOne(a, n);
    }
}

void printArray(int a[], int n)
{
    for (int j = 0; j < n; j++)
    {
        cout<<a[j]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array before rotation : ";
    printArray(arr, n);
    leftRotateArray(arr, n, 4);
    cout<<"Array After rotation : ";
    printArray(arr, n);
    return 0;
}