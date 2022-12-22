/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        //sort the intervals
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++)
        {
            if(ans.empty())
            {
                ans.push_back();
            }
            else
            {
                //check if interval is overlapping
                vector<int> &v = ans.back();
                int y = v[1]; //get end interval of last interval
                // compare current interval's start time and end time of last added
                if (intervals[i][0] < y) //overlapping found
                {
                    v[1] = max(y, intervals[i][1]);
                }
                else
                {
                    //no overlap hence push interval at end
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;      
    }
};