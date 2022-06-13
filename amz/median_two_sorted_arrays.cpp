#include<map>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> res[nums1.size() + nums2.size()];
        for(int i = 0< i<nums1.size(); i++)
        {
            m[nums1[i]] = 0;
        }
        for(int i = 0< i<nums2.size(); i++)
        {
            m[nums2[i]] = 0;
        }
        j=0;
        for(auto i: m)
        {
            res[j++] = i.first;
        }
        int med = 0;
        if(res.size() % 2 == 0) //even number of elements
        {
            int x = res.size() / 2;
            return((res[x] + res[x+1]) / 2);
        }
        else
        {
            return(res.size() / 2);
        }
    }
};