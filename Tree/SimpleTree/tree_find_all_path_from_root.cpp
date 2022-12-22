#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void pathUtil(Node* root, int arr[], int pathLen);

void printArray(int arr[], int len)
{
    for(int i = 0; i< len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void getPaths(Node* root)
{
    int path[1000];
    pathUtil(root, path , 0);
}

void pathUtil(Node* root, int arr[], int pathLen)
{
    if(root == NULL)
    {
        return;
    }

    //add node to array
    arr[pathLen] = root -> data;
    pathLen++;

    //check if this is leaf node, yes then print path
    if(root->left == NULL && root->right == NULL)
    {
        printArray(arr, pathLen);
    }
    else
    {
        // otherwise check subtree
        pathUtil(root->left, arr, pathLen);
        pathUtil(root->right, arr, pathLen);
    }
}

int main()
{
    Node* root = new Node(30);
    root -> left = new Node(20);
    root -> right = new Node(40);
    root -> left -> left = new Node(15);
    root -> left -> right = new Node(25);
    root -> right -> left = new Node(35);
    root -> right -> right = new Node(45);
    getPaths(root);
    return 0;   
}