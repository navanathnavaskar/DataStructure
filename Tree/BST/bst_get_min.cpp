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

int getMin(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
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
    printInorder(root);
    cout<<"\nMinimum Node: "<<getMin(root);
    return 0;
}