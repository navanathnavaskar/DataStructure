/*

Binary Search Algorithm: The basic steps to perform Binary Search are:

Begin with an interval covering the whole array.
If the value of the search key is less than the item in the middle of the interval, 
narrow the interval to the lower half.

Otherwise, narrow it to the upper half.
Repeatedly check until the value is found or the interval is empty.

*/

#include<iostream>
using namespace std;

int binarySearchRec(int a[], int l, int h, int key)
{
    if(l <= h)
    {
        int mid = (l+h)/2;
        if(a[mid] == key)
        {
        //cout<<"Element "<<key<<" found at "<<mid<<" position."<<endl;
            return mid;
        }

        if (key > a[mid])
        {
            return binarySearchRec(a, mid+1, h, key);
        }
        else
        {
            return binarySearchRec(a, l, mid-1, key);
        }
    }
    return -1;
}

int binarySerach(int a[], int l, int r, int key)
{
    while (l <= r)
    {
        int m = (l + r)/2;
        if(a[m] == key)
        {
            return m;
        }

        if(key > a[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {8,12,76,85,987,7699};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 76;
    cout<<key<<" found at "<<binarySerach(arr, 0, n-1, key)<<" position."<<endl;
    return 0;
}