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
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printNthInorder(node* root, int n)
{
    static int count = 0;
    if(root == NULL)
    {
        return;
    }

    if(count<=n)
    {
        printNthInorder(root->left, n);
        count++;

        if(count == n)
        {
            cout<<n<< "th Node of Inorder is "<<root->data<<endl;
        }

        printNthInorder(root->right, n);
    }
}

int main()
{
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
 
    int n = 3;
 
    printNthInorder(root, n);
    return 0;
}