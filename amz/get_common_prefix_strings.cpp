#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
        {
            return "";
        }   
        if(n == 1)
        {
            return strs[0];
        }

        //sort arrays
        sort(strs.begin(), strs.end());

        //find min length of first and last
        int mlen = min(strs[0].size(), strs[n-1].size());

        //find common prefix between 2 strings
        int i = 0;
        string fstr = strs[0];
        string lstr = strs[n-1];
        while(i < mlen && fstr[i] == lstr[i])
        {
            i++;
        }

        string res = fstr.substr(0, i);
        return res;
    }
};