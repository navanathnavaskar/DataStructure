#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        stringstream iss(s);
        int cnt = 0;
        string word;
        while(iss >> word)
        {
            cnt++;
            res.append(word);
            if(cnt == k)
            {
                break;
            }
        }
        return res;      
    }
};