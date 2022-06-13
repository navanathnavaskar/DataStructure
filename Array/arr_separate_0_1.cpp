/*
Program to separate 0 and 1.
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void separate0and1(int a[],int n)
{
    int type0 = 0;
    int type1 = n-1;

    while(type0<type1)
    {
        if(a[type0] == 1)
        {
            if(a[type1] != 1) //then swap
            {
                swap(a[type0], a[type1]);
            }
            type1--;
        }
        else
        {
            type0++;
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
    int a[] = {0,1,0,0,1,1,1,0};

    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    separate0and1(a, n);
    printArray(a, n);
    return 0;
}