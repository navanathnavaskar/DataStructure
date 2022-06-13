#include<iostream>
#include<limits.h>
using namespace std;

void maxSumSubArray(int a[], int n)
{
    int curr_max_sum = INT_MIN;
    int max_sum_here = 0;
    int start = 0 , end = 0;
    int p = 0;
    for(int i = 0; i < n; i++)
    {
        max_sum_here += a[i];

        if(curr_max_sum < max_sum_here)
        {
            curr_max_sum = max_sum_here;
            start = p;
            end = i;
        }

        if(curr_max_sum < 0)
        {
            p = p + i;
            max_sum_here = 0;
        }
    }
    cout<<"Max Sum of Sub Array from position "<<start<<" to "<<end<<" is : "<<curr_max_sum;
}

int main()
{
    int arr[] = {-1,-2,3,-1,-2,-1,-4};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxSumSubArray(arr, n);
    return 0;
}