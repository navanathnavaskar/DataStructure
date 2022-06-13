#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++)
        {
            m[s[i]] = i;
        }
        int max = 0;
        string result = "";
        for(int i = 0; i < s.size(); i++)
        {
            checkIfLong(s, i , m[s[i]], max, result);
        }
        return result;
    }

    void checkIfLong(string str, int start, int end, int &max, string &res)
    {
        int s = start, e = end;
        int flag = 1;
        while(start< end)
        {
            if(str[start++] != str[end--])
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
            //get substring
            string sub = str.substr(s, e - s + 1);
            if(max < sub.size())
            {
                res = sub;
                max = sub.size();
            }
        }
    }
};
