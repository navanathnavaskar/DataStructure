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

bool isLeaf(node* root)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

int sumLeftLeaves(node* root)
{
    int res = 0;
    if(root != NULL)
    {
        if(isLeaf(root))
        {
            res += root->data;
        }
        else
        { // Goto left sub tree
            res += sumLeftLeaves(root->left);
        }
        //goto right subtree
        res += sumLeftLeaves(root->right);
    }
    return res;
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

    cout<<"Sum Left Leaves : "<<sumLeftLeaves(root);
    return 0;
}