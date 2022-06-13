#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            unordered_set<int> s;
            for(int j = i + 1; j < n; j++)
            {
                int x = -(nums[i] + nums[j]);
                if(s.find(x) != s.end())
                {
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(x);
                    result.push_back(a); 
                }
                else
                {
                    s.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

/*
void get3sum(int a[], int n)
{

    bool flag = false;
    for(int i = 0; i<n-1 ; i++)
    {
        unordered_set<int> s;
        for(int j = i + 1; j <n; j++)
        {
            int x = -(a[i] + a[j]);
            if(s.find(x) != s.end() )
            {
                cout<<"Found numbers : "<<a[i]<<" "<<a[j]<<" "<<x<<endl;
                flag = true;
            }
            else
            {
                s.insert(a[j]);
            }
        }
    }
    if(flag == false)
    {
        cout<<"Elements not present !"<<endl;
    }
}
*/

int main()
{
    class Solution s1; 
    vector<int> A = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s1.threeSum(A);
    for(int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}