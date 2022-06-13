/*
Find k’th character of decrypted string | Set 1

Given an encoded string where repetitions of substrings are represented as substring followed by count of substrings. 
For example, if encrypted string is “ab2cd2” and k=4 , so output will be ‘b’ because decrypted string is “ababcdcd” and 
4th character is ‘b’.
Note: Frequency of encrypted substring can be of more than one digit. 
For example, in “ab12c3”, ab is repeated 12 times. No leading 0 is present in frequency of substring. 
*/

#include<iostream>
#include<string>
using namespace std;

char getCharAtDecoded(string s, int index)
{
    string temp = "";
    string expand = "";
    int j = 0;
    int freq = 0;
    for(j = 0;s[j] != '\0';)
    {
        temp = "";
        freq = 0;
        //first get string/char into temp
        while(s[j] >= 'a' && s[j] <= 'z')
        {
            temp.push_back(s[j]);
            j++;
        } 

        //now get frequency
        while(s[j] >= '0' && s[j] <= '9')
        {
            freq = freq * 10 + (s[j] - '0');
            j++;
        }

        //now add temp data freq times into expand.
        for(int k = 0; k < freq; k++)
        {
            expand.append(temp);
        }
    }
    //handle case where decoded string has alphabets at end
    if(freq = 0)
    {
        expand.append(temp);
    }
    return expand[index-1];
}

int main()
{
    string str = "a2b3c5ed10";
    char c = getCharAtDecoded(str, 13);
    cout<<"Char at : "<<c;
    return 0;
}