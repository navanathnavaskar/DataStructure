/*
Program to find second largest of array
*/

#include<iostream>
#include<limits.h>

using namespace std;

void findSecondLargest(int a[], int n)
{
    int first = INT_MIN;
    int second = INT_MIN;

    if(n<2)
    {
        cout<<"Invalid Input array"<<endl;
    }

    for(int j = 0; j<n; j++)
    {
        if(a[j] > first) //if > first then replace both
        {
            second = first;
            first = a[j];
        }
        else if(a[j] > second) // change second if number between first and second
        {
            second = a[j];
        }
    }

    if(second == INT_MIN)
    {
        cout<<"No second Lagest element found in array"<<endl;
    }
    else
    {
        cout<<second<<" is the second largest element in array."<<endl;
    }
}


int main()
{
    int arr[] = {34,12,86,87,32,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    findSecondLargest(arr, n);
    return 0;
}