/*
Distinct adjacent elements in an array

Given an array, find whether it is possible to obtain an array having distinct 
neighbouring elements by swapping two neighbouring array elements.
Examples: 

Input : 1 1 2
Output : YES
swap 1 (second last element) and 2 (last element), 
to obtain 1 2 1, which has distinct neighbouring 
elements .

Input : 7 7 7 7
Output : NO
We can't swap to obtain distinct elements in 
neighbor .

if n is number of elements in array then no. of occurances of same element should be <= half of array size.
*/
#include<bits/stdc++.h>
using namespace std;

void isReorder(int a[], int n)
{
    map<int, int> m;

    for(int i = 0; i< n; ++i)
    {
        m[a[i]]++;
    }

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(m[a[i]] > mx)
        {
            mx = m[a[i]];
        }
    }

    if(mx > (n+1) / 2 )
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES"<<endl;
    }
}

int main()
{
    int a[] = { 2,1,1,1 };
    int n = sizeof(a) / sizeof(a[0]);
    isReorder(a, n);
    return 0;
}