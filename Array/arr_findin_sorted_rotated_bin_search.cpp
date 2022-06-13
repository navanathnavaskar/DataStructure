// C++ program to find element in sorted and rotated array
#include <iostream>
using namespace std;
int binarySearch(int a[], int low, int high, int key)
{
    if(high<low)
    {
        return -1;
    }
    
    int mid = (low + high)/2;
    
    if(a[mid] == key)
    {
        return mid;
    }
    
    if(key < a[mid])
    {
        return binarySearch(a, low, mid-1,key);
    }
    else
    {
        return binarySearch(a,mid+1,high,key);
    }
}

int findPivot(int a[], int n)
{
    int i = 0;
    for(i = 0; i <= n-2; i++)
    {
        if(a[i] > a[i+1])
        {
            break;
        }
    }
    return i;
}

// Driver Code
int main()
{
    int arr[] = { 4,5,6,7,1,2,3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int pivot = findPivot(arr,n);
    cout<<"Pivot : "<<pivot<<endl;
    
    if (arr[pivot] == key)
    {
        cout<<"Nath3";
        cout<<"Key FOund at: "<<pivot;
    }
    else if(key >= arr[pivot+1])
    {
        cout<<"Nath1";
        cout<<"Found at : "<< binarySearch(arr,pivot+1,n-1,key);
    }
    else
    {
        cout<<"Nath";
        cout<<"Found at : "<< binarySearch(arr,0, pivot-1,key);
    }

    return 0;
}