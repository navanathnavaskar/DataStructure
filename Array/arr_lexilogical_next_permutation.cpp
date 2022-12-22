/*
The Idea is Based on the Following Facts: 

A sequence sorted in descending order does not have the next permutation. 
For example “edcba” does not have the next permutation.
For a sequence that is not sorted in descending order for example “abedc”, we can follow these steps.  
a) Traverse from the right and find the first item that is not following the ascending order. 
For example in “abedc”, the character ‘b’ does not follow the ascending order.
b) Swap the found character with the closest greater (or smallest greater) element 
on the right side of it. In the case of “abedc”, we have ‘c’ as the closest greater element. 
After swapping ‘b’ and ‘c’, the string becomes “acedb”.
c) After swapping, reverse the string after the position of the character found in step a. 
After reversing the substring “edb” of “acedb”, we get “acbde” which is the required next permutation. 
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    void printData(vector<int> &nums)
    {
        int n = nums.size();
        cout<<"[";
        for(int i = 0; i < n; i++)
        {
            cout<<nums[i];
            if(i != n-1)
            {
                cout<<",";
            }
        }
        cout<<"]";
    }

    void nextPermutation(vector<int>& nums) {
        bool val = next_permutation(nums.begin(), nums.end());
        if(val)
        {
            printData(nums);   
        }
        else
        {
            sort(nums.begin(), nums.end());
            printData(nums);
        }
    }
};