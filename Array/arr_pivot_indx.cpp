/*
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            rsum -= nums[i];
            if(rsum == lsum)
            {
                return i;
            }
            lsum += nums[i];
        }
        return -1;
    }
};