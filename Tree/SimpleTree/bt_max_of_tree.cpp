#include<limits.h>
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
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int getMax(node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    int res = root->data;
    int lres = getMax(root->left);
    int rres = getMax(root->right);

    if(lres > res)
        res = lres;
    if(rres > res)
        res = rres;
    
    return res;
}

int main()
{
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(80);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    cout<<"Max From tree : "<<getMax(root);
    return 0;
}