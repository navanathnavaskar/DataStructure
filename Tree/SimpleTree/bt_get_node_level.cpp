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

int getLevel(node* root, int data, int level)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->data == data)
    {
        return level;
    }

    int downlevel = getLevel(root->left, data, level + 1);
    if(downlevel)
        return downlevel;

    downlevel = getLevel(root->right, data, level + 1);
    return downlevel;
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

    cout<<"Level of 40 : "<<getLevel(root, 40, 1);
    return 0;
}