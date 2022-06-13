#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int isneg = 0;
        if(x < 0)
        {
            isneg = 1;
        }
        int res = 0;
        while(x>0)
        {
            res = res * 10 + (x % 10);
            x = x / 10;
        }
        return (res)
    }
};