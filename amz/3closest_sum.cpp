#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = 1000000000;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int fptr = i + 1;
            int lptr = nums.size() - 1;

            while(fptr < lptr)
            {
                //calculate sum
                int sum = nums[i] + nums[fptr] + nums[lptr];

                //check if sum is more closer than prev sum
                if(abs(target - sum) < abs(target - closestSum))
                {
                    closestSum = sum;
                }

                if(sum > target)
                {
                    lptr--;
                }
                else
                {
                    fptr++;
                }
            }
        }
        return closestSum;
    }
};