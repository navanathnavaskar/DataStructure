/*
Given a pattern containing only I’s and D’s. I for increasing and D for decreasing. 
Device an algorithm to print the minimum number following that pattern. 
Digits from 1-9 and digits can’t repeat.

Examples: 

   Input: D        Output: 21
   Input: I        Output: 12
   Input: DD       Output: 321
   Input: II       Output: 123
   Input: DIDI     Output: 21435
   Input: IIDDD    Output: 126543
   Input: DDIDDIID Output: 321654798
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void minform(string input)
{
    string out;
    stack<int> s;

    for(int i = 0; i <= input.length(); i++)
    {
        s.push(i+1); // push i+1 to stack for all

        //if this is end of sequence or current char is "I"
        // Pop stack and add to result.
        if(i == input.length() || input[i] == 'I')
        {
            while(!s.empty())
            {
                out += " ";
                out += to_string(s.top());
                s.pop();
            }
        }
    }
    cout<<out<<endl;
}

int main()
{
    minform("IDID");
    minform("I");
    minform("DD");
    minform("II");
    minform("DIDI");
    minform("IIDDD");
    minform("DDIDDIID");
    return 0;
}


