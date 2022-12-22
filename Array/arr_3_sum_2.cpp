//Using 2 pointers
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            int j = i+1;
            int k = n-1;
            while(j < n && j < k)
            {
                if(nums[j] + nums[k] == -nums[i])
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    //remove duplicates
                    while(j != n-1 && nums[j] == nums[j+1])
                    {
                        j++;
                    }
                    while(k >= 0 && nums[k] == nums[k+1])
                    {
                        k--;
                    }
                    j++;k--;
                }
                else if(nums[j]+nums[k] > -nums[i])
                {
                    while(k >= 0 && nums[k] == nums[k+1])
                    {
                        k--;
                    }
                    k--;
                }
                else
                {
                    while(j != n-1 && nums[j] == nums[j+1])
                    {
                        j++;
                    }
                    j++;
                }
            }
            while(i != n-1 && nums[i] == nums[i+1])
            {
                i++;
            }    
        }

        for(auto tuple: result)
        {
            sort(tuple.begin(), tuple.end());
        }
        return result;
    }
};