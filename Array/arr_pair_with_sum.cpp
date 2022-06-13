/*
Given an array A[] and a number x, check for pair in A[] with sum as x

Using two pointer technique

Let an array be {1, 4, 45, 6, 10, -8} and sum to find be 16
After sorting the array 
A = {-8, 1, 4, 6, 10, 45}
Now, increment ‘l’ when the sum of the pair is less than the required sum and decrement ‘r’ when the sum of the pair is more than the required sum. 
This is because when the sum is less than the required sum then to get the number which could increase the sum of pair, start moving from left to right(also sort the array) thus “l++” and vice versa.
Initialize l = 0, r = 5 
A[l] + A[r] ( -8 + 45) > 16 => decrement r. Now r = 4 
A[l] + A[r] ( -8 + 10) increment l. Now l = 1 
A[l] + A[r] ( 1 + 10) increment l. Now l = 2 
A[l] + A[r] ( 4 + 10) increment l. Now l = 3 
A[l] + A[r] ( 6 + 10) == 16 => Found candidates (return 1)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int isSum(int a[], int n, int sum)
{
    sort(a, a+n);
    int l = 0, r = n-1;

    while(l<r)
    {
        if(a[l] + a[r] == sum)
        {
            return 1;
        }
        if(a[l] + a[r] > sum)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return 0;
}

int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    // Function calling
    if (isSum(A, arr_size, n))
        cout << "Array has two elements"
                " with given sum";
    else
        cout << "Array doesn't have two"
                " elements with given sum";
 
    return 0;
}
