/*
program to find c2 = a2+b2;
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int istriplet(int a[], int n)
{
    set<int> s;

    for(int i = 0; i < n; i++)
    {
        a[i] = a[i] * a[i];
    }

    int k = 0;
    sort(a, a+n);
    for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            s.insert(a[i] + a[j]);
        }
    }
    
    for(int i = 0; i<n;i++)
    {
        if(s.find(a[i]) != s.end())
            return 1;
    }
    return 0;
}

int main()
{
    int arr[] = { 13, 2, 4, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (istriplet(arr, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}