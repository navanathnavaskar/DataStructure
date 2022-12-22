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

void getPreSuc(node* root, node* &suc, node* &pre, int key)
{
    // base case
    if(root == NULL)
    {
        return;
    }

    // If key found get predecessor and successor 
    if (key == root->data)
    {
        // predecessor is in left subtree - max from left subtree
        if (root->left)
        {
            node* tmp = root->right;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            pre = tmp;
        }

        // successor is in right subtree - min from right subtree
        if(root->right)
        {
            node* tmp = root->left;
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            suc = tmp;            
        }
    }

    //if key is less then search in left subtree else in right subtree
    if(key < root->data)
    {
        suc = root;
        getPreSuc(root->left,suc, pre,key);        
    }
    else
    {
        pre = root;
        getPreSuc(root->right, suc, pre, key);
    }
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
    node* pre = NULL;
    node* suc = NULL;
    getPreSuc(root, pre, suc, 7);
    if(pre == NULL)
    {
        cout<<"No predeccesor"<<endl;
    }
    else
    {
        cout<<pre->data<<endl;
    }
    if(suc == NULL)
    {
        cout<<"No successor"<<endl;
    }
    else
    {
        cout<<suc->data<<endl;
    }
    return 0;
}