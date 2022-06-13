/*
K’th Smallest/Largest Element in Unsorted Array | Set 1

Given an array and a number k where k is smaller than the size of the array, 
we need to find the k’th smallest element in the given array. 
It is given that all array elements are distinct.

Examples:  

    Input: arr[] = {7, 10, 4, 3, 20, 15} 
    k = 3 
    Output: 7
*/

#include<algorithm>
#include<iostream>
using namespace std;

void kthsmallest(int a[], int n, int k)
{
    sort(a, a+n);

    cout<<k<<" smallest = "<<a[k-1]<<endl;
}

int main()
{
    int a[] = {23,6,2,91,7,14};
    int n = sizeof(a)/sizeof(a[0]);
    kthsmallest(a,n,3);
    return 0;
}

