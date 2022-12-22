//You can buy as many as stocks but can hold only one at a time
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            profit += max(prices[i] - prices[i-1], 0);
        }
        return profit;
    }
};