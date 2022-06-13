#include <sstream>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
void tokens(char str[])
{
    char *token = strtok(str, "_");
    
    while(token != NULL)
    {
        cout<<"\n"<<token;
        token = strtok(NULL, "_");
    }
}

//This is thread safe
void token_r(char str[])
{
    char *rest = str;
    char *token;
    while(token = strtok_r(rest,"_", &rest))
    {
        cout<<"\n"<<token;
    }
}

void token_ss()
{
    string my = "My Name is Nath";
    stringstream iss(my);
    string res;
    vector<string> tokens;
    while(getline(iss, res, ' '))
    {
        tokens.push_back(res);
    }
    
    for(int i = 0;i<tokens.size();i++)
    {
        cout<<"\n"<<tokens[i];
    }
}

int main()
{
    char s[] = "abc_pune_maha";
    token_r(s);
    token_ss();
    return 0;
}