#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            ans.push_back(product);
            product *= nums[i];
        }
        product = 1;
        for(int i=0;i<n;i++)
        {
            ans[i] *= product;
            product *= nums[i];
        }
        return nums;
    }
};