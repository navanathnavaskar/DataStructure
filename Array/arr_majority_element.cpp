/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
Input: nums = [3,2,3]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int target = nums.size()/2;
        if(nums.size() % 2 == 1)
        {
            target++;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            m[nums[i]]++;
            if(m[nums[i]] >= target)
                return nums[i];
        }
        return -1;
    }
};