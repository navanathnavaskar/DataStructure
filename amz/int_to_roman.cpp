#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int s1, s2, i;
        int res = 0;
        while(i < s.length())
        {
            s1 = getValue(s[i]);
            if(i+1 <s.length())
            {
                s2 = getValue(s[i+1]);
                if(s1 > s2)
                {
                    res = res + s1;
                }
                else
                {
                    res = res + s2 - s1;
                    i++;
                }
            }
        }
        return res;
    }

    int getValue(char ch)
    {
        if(ch == 'M')
        {
            return 1000;
        }
        else if(ch == 'D')
        {
            return 500;
        }
        else if(ch == 'C')
        {
            return 100;
        }
        else if(ch == 'L')
        {
            return 50;
        }
        else if(ch == 'X')
        {
            return 10;

        }
        else if(ch == 'V')
        {
            return 5;
        }
        else if(ch == 'I')
        {
            return 1;
        }
        return -1;
    }
};