/*
Given an array of elements of length N, ranging from 0 to N – 1. 
All elements may not be present in the array. If the element is not present then there will be -1 present in the array. 
Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
*/
#include <iostream>
#include <unordered_set>
using namespace std;

void fixArray(int a[], int n)
{
    unordered_set<int> s;
    
    for(int i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            s.insert(a[i]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(s.find(i) != s.end())
        {
            a[i] = i;
        }
        else
        {
            a[i] = -1;
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
