#include<bits/stdc++.h>
using namespace std;
#define PS1_PRESENT 0x80
#define PS1_STATUS 0x40
#define PS1_TYPE 0x20
#define PS2_PRESENT 0x04
#define PS2_STATUS 0x02
#define PS2_TYPE 0x01

void getStatus(unsigned int *value)
{
    if(PS1_PRESENT & *value)
    {
        cout<<"PS1 is present."<<endl;
    }
    else
    {
        cout<<"PS1 is absent."<<endl;
    }
    if(PS1_STATUS & *value)
    {
        cout<<"PS1 is Healthy."<<endl;
    }
    else
    {
        cout<<"PS1 is Failed."<<endl;
    }
    if(PS1_TYPE & *value)
    {
        cout<<"PS1 is AC."<<endl;
    }
    else
    {
        cout<<"PS1 is DC."<<endl;
    }
    if(PS2_PRESENT & *value)
    {
        cout<<"PS2 is present."<<endl;
    }
    else
    {
        cout<<"PS2 is absent."<<endl;
    }
    if(PS2_STATUS & *value)
    {
        cout<<"PS2 is Healthy."<<endl;
    }
    else
    {
        cout<<"PS2 is Failed."<<endl;
    }
    if(PS2_TYPE & *value)
    {
        cout<<"PS2 is AC."<<endl;
    }
    else
    {
        cout<<"PS2 is DC."<<endl;
    }
}

int main()
{
    unsigned int data = 0x0f;
    getStatus(&data);
    return 0;
}