
void allStrings(string str)
{
    string tmp = str+str;
    //cout<<tmp;
    int len = str.length();
    for(int i=0;i<len;i++)
    {
        int j = 0;
        for(j=0;j!=len;j++)
        {
            cout<<tmp[i+j];
        }
        cout<<"\n";
    }
    
}

int main()
{
    string str = "abcd";
    allStrings(str);
    return 0;
}