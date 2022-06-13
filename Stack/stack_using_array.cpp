/*
Stack implementation using array.
*/

#include<bits/stdc++.h>
#define MAX 10
using namespace std;

class Stack
{
    int A[MAX];
    int top;
public:
    Stack()
    {
        top = -1;
    }

    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::push(int x)
{
    if(top > MAX)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    A[++top] = x;
    cout<<"Data "<<x<<" added in stack"<<endl;
}

int Stack::pop()
{
    if(top < -1)
    {
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    return A[top--];
}

bool Stack::isEmpty()
{
    return (top<-1) ? true: false;
}

int Stack::peek()
{
    if(top < -1)
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    return A[top];
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Is stack empty : "<<s.isEmpty()<<endl;
    cout<<"Get top value : "<<s.peek()<<endl;
    cout<<"removed "<<s.pop()<<" from stack"<<endl;
    return 0;
}