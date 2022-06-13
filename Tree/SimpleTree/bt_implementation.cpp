/*

Binary tree implementation.

*/

#include<iostream>
#include<queue>
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
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;  
}

node* insertNode(node* root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    queue<node*> q;
    q.push(root);

    while (! q.empty())
    {
        node* temp = q.front();
        //remove node from front
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = createNode(data);
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        if(temp->right == NULL)
        {
            temp->right = createNode(data);
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}

void printInorder(node* root)
{
    if(root == NULL)
        return;
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(node* root)
{
    if(root == NULL)
        return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

void printPreorder(node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    node* root = NULL;
    root = createNode(10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    cout<<"\nInorder Traversal : ";
    printInorder(root);
    cout<<"\nPreorder Traversal : ";
    printPreorder(root);
    cout<<"\nPostorder Traversal : ";
    printPostorder(root);
    return 0;
}