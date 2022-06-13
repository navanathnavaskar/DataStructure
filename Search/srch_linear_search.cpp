/*
Search element in linear O(n) time
*/
#include<iostream>
using namespace std;

int linearSearch(int a[], int n, int key)
{
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int linearSearchOpt(int a[], int n, int key)
{
    int left = 0, right = n-1;
    while(left <= right)
    {
        if(a[left] == key)
        {
            return left;
        }
        
        if(a[right] == key)
        {
            return right;
        }
        left++;
        right--;
    }
    return -1;
}

int main()
{
    int arr[] = {12,54,1,76,232,123,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 76;
    cout<<key<<" found at "<<linearSearchOpt(arr, n, key) + 1<<" position."<<endl;
    return 0;
}
