/*
Find inorder successor of node.
*/

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
    node* temp = (node*) malloc (sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderSuccessor(node* root, node* t_node, node* &next)
{
    if(root == NULL)
    {
        return;
    }

    inorderSuccessor(root->right, t_node, next);
    if(root->data == t_node->data)
    {
        if(next == NULL)
        {
            cout<<"Inorder Successor of "<<t_node->data <<" is NULL"<<endl;
        }
        else
        {
            cout<<"Inorder Successor of "<<t_node->data <<" is "<< next->data<<endl;
        }
    }

    next = root;

    inorderSuccessor(root->left, t_node, next);
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

    node* next = NULL;
    inorderSuccessor(root, root, next);
    next = NULL;
    inorderSuccessor(root, root->left->left, next);
    next = NULL;
    inorderSuccessor(root, root->right->right, next);
    return 0;
}