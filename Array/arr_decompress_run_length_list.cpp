#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i+=2)
        {
            int freq = nums[2*i];
            int val = nums[2*i+1];
            for(int j = 0; j < freq; j++)
                res.push_back(nums[i]);
        }
        return res;
    }
};