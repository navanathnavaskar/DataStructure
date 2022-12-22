#include<bits/stdc++.h>
using namespace std;

void getSubsets(int arr[], int size)
{
    int subsetSize = pow(2, size);

    for(int counter = 0; counter < subsetSize; counter++)
    {
        for(int i = 0; i < size; i++)
        {
            if(counter & (1 << i))
            {
                // if bit is set then print element at i
                cout<<arr[i];
            }
        }
        cout<<endl;
    }
}

int main()
{
    int arr[] = {2,4,5};
    getSubsets(arr, 3);
    return 0;
}