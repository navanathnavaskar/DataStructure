/*
1,2,3 -> 1,2,4
1,2,9 -> 1, 3, 0
9, 9, 9 -> 1,0,0,0
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }

        vector<int> number (n+1, 0);
        number[0] = 1;
        return number;
    }
};