#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left, *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class bstit 
{
private:
    stack<node*> s;
public:
    bstit(node* root)
    {
        node* curr = root;
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr ->right;
        }
    }

    node* current()
    {
        return s.top();
    }

    void prev()
    {
        node* curr = s.top() -> left;
        s.pop();
        while (curr != NULL)
        {
            s.push(curr), curr = curr->right;
        }
    }

    bool isEnd()
    {
        return (s.empty());
    }
};

int main()
{
    node* root = new node(5);
    root -> left = new node(3);
    root -> right = new node(7);
    root -> left -> left = new node(2);
    root -> left -> right = new node(4);
    root -> right -> left = new node(6);
    root -> right -> right = new node(8);

    bstit it(root);

    while (! it.isEnd())
    {
        cout<<" "<<it.current() -> data, it.prev();
    } 
    return 0;
}