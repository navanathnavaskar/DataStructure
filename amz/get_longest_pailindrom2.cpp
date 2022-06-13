#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        
        string result = "";
        int max = 1;
        int n = s.size();
        int start = 0;
        int low , high ;
        for(int i = 0; i<n; i++)
        {
            low = i - 1;
            high = i + 1;

            while(high < n && s[high] == s[i])
            {
                high++;
            }

            while(low >= 0 && s[low] == s[i])
            {
                low--;
            }

            while(low >= 0 && high<n && s[low] == s[high])
            {
                low--;
                high++;
            }
            int len = high - low - 1;
            if(max < len)
            {
                max = len;
                start = low + 1;
            }
        }
        result = s.substr(start, start + max -1);
        return result;
    }    
};
