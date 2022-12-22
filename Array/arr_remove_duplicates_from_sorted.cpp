/*

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i=1; i < nums.size();i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[k++] = nums[i-1];
            }          
        }
        nums[k++] = nums[nums.size()-1]; 
        return k;
    }
};