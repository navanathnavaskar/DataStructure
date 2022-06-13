/*
Replace two consecutive equal values with one greater

You are given an array of size ‘n’. You have to replace every pair of consecutive 
values ‘x’ by a single value ‘x+1’ every time until there is no such repetition left 
and then print the new array. 

    Input : 5, 2, 1, 1, 2, 2 
    Output : 5 4 
*/

#include<iostream>
using namespace std;

void replace(int a[], int n)
{
    int pos = 0;

    for(int i = 0; i < n; i++)
    {
        a[pos++] = a[i];

        while(pos > 1 && a[pos-2] == a[pos-1])
        {
            pos--;
            a[pos-1]++;
        }
    }
    for(int i = 0; i < pos; i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    int a[] = {5,2,1,1,2,2};
    int n = sizeof(a)/sizeof(a[0]);
    replace(a,n);
    return 0;
}