#include<unordered_map>
#include<iostream>
using namespace std;

void getTwoSum(int a[], int n, int t)
{
    unordered_map<int,int> m;
    for(int i =0; i < n; i++)
    {
        m[a[i]] = i;
    }

    for(int i=0; i<n; i++)
    {
        int r = t-a[i];
        //cout<<"a[i] = "<<a[i]<<" r = "<<r<<endl;
        if(m.find(r) != m.end())
        {
            cout<<"Found Pair ("<<i<<","<<m[r]<<")"<<endl;
            return;
        }
    }
    cout<<"Failed to get required pair"<<endl;

}

int main()
{
    int arr[] = {31,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    getTwoSum(arr, n, 10);
    return 0;
}