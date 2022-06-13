#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;

node* createNode(int data)
{
    node* temp = (node*) malloc(sizeof(node));
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
}

int getHeight(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if(lh > rh)
        {
            return lh+1;
        }
        else
        {
            return rh+1;
        }
    }
}

int main()
{
    node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    cout<<"Height of the tree is : "<<getHeight(root);
    return 0;
}