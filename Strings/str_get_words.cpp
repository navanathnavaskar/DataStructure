#include<iostream>
#include<sstream>
#include<string>

using namespace std;

void getWords(string str)
{
    stringstream iss(str);
    string word;
    while(! iss.eof())
    {
        iss >> word;
        cout<<word<<endl;
    }
}

int main()
{
    string str = "Pune is best city to live in";
    getWords(str);
    return 0;
}