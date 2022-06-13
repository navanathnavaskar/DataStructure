/*
Arrange given numbers to form the biggest number

Given an array of numbers, arrange them in a way that yields the largest value. 
For example, if the given numbers are {54, 546, 548, 60}, 
the arrangement 6054854654 gives the largest value. 

And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, 
then the arrangement 998764543431 gives the largest value.
*/

#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    
    string YX = Y.append(X);
    
    return XY.compare(YX) > 0 ? 1 : 0;
}

void printLargest(vector<string> arr)
{
    sort(arr.begin(), arr.end(), myCompare);
    
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i];
    }
}

int main()
{
    vector<string> arr;
    
    arr.push_back("42");
    arr.push_back("6");
    arr.push_back("59");
    
    printLargest(arr);
    return 0;
}