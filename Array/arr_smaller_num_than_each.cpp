#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> resf(nums.size());
        vector<int> temp(nums.size());
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            temp[i] = nums[i];
            mp[temp[i]] = -1;
        }
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[temp[i]] == -1)
            {
                //element not found
                mp[temp[i]] = n - (n-i);
                res[i] = mp[temp[i]];
            }
            else
            {
                res[i] = mp[temp[i]];
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            resf[i] = mp[nums[i]];
        }
        return resf;
    }
};