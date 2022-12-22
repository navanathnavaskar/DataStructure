#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        map<int, int> mp;
        for(int i = nums.size(); i >= 0; i--)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] - nums[j] == diff)
                {
                    cout<<"("<<i<<","<<j<<")"<<endl;
                    mp[i] = j;
                }
                else if(nums[i] - nums[j] > diff)
                {
                    break;
                }
            }
        }
        
        for(auto m : mp)
        {
            if(mp.find(m.second) != mp.end())
            {
                count++;
            }
        }
        return count;
    }
};