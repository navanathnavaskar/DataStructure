#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length() == 0)
        {
            return result;
        }
        string letters[10] = { "0",   "1",   "abc",  "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz" };
        queue<string> q;
        q.push("");
        while(!q.empty())
        {
            string s = q.front();
            q.pop();

            if(s.length() == digits.length())
            {
                result.push_back(s);
            }
            else
            {
                int l = digits[s.length()] - '0';
                string str = letters[l];
                for(int i = 0 ; i < str.length(); i++)
                {
                    q.push(s + str[i]);
                }
            }
        }
        return result;  
    }
};