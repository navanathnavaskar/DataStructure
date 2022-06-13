/*
Rearrange array such that even positioned are greater than odd

Input : A[] = {1, 3, 2}
Output : 1 3 2
Explanation : 
Here, the array is also sorted as per the conditions. 
1  1 and 2 < 3.
*/

#include<iostream>
using namespace std;
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t; 
}

void arrangeArr(int a[], int n)
{
    for(int i = 1; i< n; i++)
    {
        if(i%2==0) //even position
        {
            if(a[i] > a[i-1])
            {
                Swap(&a[i], &a[i-1]);
            }
        }
        else //odd position
        {
            if(a[i] < a[i-1])
            {
                Swap(&a[i], &a[i-1]);
            }
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    arrangeArr(arr, n);

    for(int j = 0; j<n; j++)
    {
        cout<<"\t"<<arr[j];
    }
}