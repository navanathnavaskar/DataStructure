#include<string>
#include<iostream>
#include<sstream>
#include<map>
using namespace std;

void getWordCount(string str)
{
    stringstream iss(str);
    map<string, int> m;
    string word;
    while(iss >> word)
    {
        m[word]++;
    }

    map<string, int> :: iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<< " : " <<it->second<<endl;
    }
}

int main()
{
    string str = "geeks for geeks and pune is my pune";
    getWordCount(str);
    return 0;
}