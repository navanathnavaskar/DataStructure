#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> s;
        temp.resize(3);
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                //check if -(b+c) is present 
                if(binary_search(nums.begin()+j+1. nums.end(), -nums[i]-nums[j]))
                {
                    //a+b+c = 0 present
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = -nums[i]-nums[j];
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
        for(auto tuple: s)
        {
            result.push_back(tuple);
        }
        return result;
    }
};