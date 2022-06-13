#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int area = 0;
        while(low < high)
        {
            area = max(area, min(height[low], height[high]) * (high - low));

            if(height[low] < height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return area;
    }
};