/*
1) Iterate through elements in an array 
2) If arr[i] >= 0 && arr[i] != i, put arr[i] at i ( swap arr[i] with arr[arr[i]])
*/

#include <iostream>
using namespace std;

void fixArray(int a[], int n)
{
    for(int i = 0 ;i < n; i++)
    {
        if(a[i] >= 0 && a[i] != i)
        {
            //swap a[i] with a[a[i]]
            int t = a[i];
            a[i] = a[a[i]];
            a[a[i]] = t;
        }
        else
        {
            i++;
        }
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
    int arr[] = {-1,-1,2,5,8,-1,-1,-1,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before fix:\n";
    printArray(arr,n);
    fixArray(arr, n);
    cout<<"Array after fix:\n";
    printArray(arr, n);
    return 0;
}