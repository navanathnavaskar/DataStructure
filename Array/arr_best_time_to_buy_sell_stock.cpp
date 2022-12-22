#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = INT_MIN;
        int minstock = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            maxprofit = max(maxprofit, prices[i] - minstock);
            minstock = min(minstock, prices[i]);
        }
        return maxprofit;
    }
};