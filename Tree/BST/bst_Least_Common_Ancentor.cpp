/*
Lowest Common Ancestor in a Binary Search Tree.
*/

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

typedef struct Node node;

node* createNode(int data)
{
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int data)
{
    if(root == NULL)
    {
        node* temp = createNode(data);
        return temp;
    }

    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void printInorder(node* root)
{
    if(root != NULL)
    {
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}

int getLCA(node* root, int l1, int l2)
{
    while(root != NULL)
    {
        if(root->data <l1 && root->data < l2)
        {
            root = root->left;
        }
        else if(root->data > l1 && root->data >l2)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return root->data;
}

int main()
{
    node* root = createNode(20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 60);
    root = insert(root, 50);
    //printInorder(root);
    cout<<getLCA(root, 10,30)<<endl;
    return 0;
}