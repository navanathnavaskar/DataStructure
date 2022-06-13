class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
        {
            return s;
        }
        string result;
        int step = 2 * numRows -2;
        for(int i = 0; i<numRows; i++)
        {
            for(int j = i; j < s.size(); j += step)
            {
                result.push_back(s[j]);
                if(i != 0 && i != numRows - 1 && (j + step - 2 * i ) < s.size())
                {
                    result.push_back(s[j + step - 2 * i]);
                }
            }
        }
        return result;
    }
};