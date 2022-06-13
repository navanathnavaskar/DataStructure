#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0; i<n; i++)
        {
            vector<bool> visitedChar[256];
            for(int j = i; j<n; j++)
            {
                if(visitedChar[s[j]])
                {
                    break;
                }
                else
                {
                    visitedChar[s[j]] = true;
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};