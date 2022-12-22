/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currSum = 0;
        map<int, int> m;
        m[0] = 1;
        int ans = 0;
        int n = nums.size()
        for(int i = 0; i < n; i++)
        {
            currSum += nums[i];
            ans += m[currSum - k];
            m[currSum]++; // increment currSum count in map
        }
        return ans;
    }
};