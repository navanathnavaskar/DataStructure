#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result = {-1,-1};
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end())
            {
                result[0] = i;
                result[1] = m[target-m[target-nums[i]]];
                break;
            }
        }
        return result;        
    }
};

int main()
{
    class Solution s;
    vector<int> arr = {3,4,6,7};
    vector<int> res;
    res = s.twoSum(arr, 10);
    if(res[0] != -1)
    {
        cout<<"Found Pair ("<<res[0]<<","<<res[1]<<")"<<endl;
    }
    else
    {
        cout<<"No such pair exist";
    }
}