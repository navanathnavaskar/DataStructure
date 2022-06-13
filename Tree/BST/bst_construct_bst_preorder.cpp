#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};

typedef struct Node node;

node* createNode(int data)
{
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insertNodePreorder(node* root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if(data < root->data)
    {
        root->left = insertNodePreorder(root->left, data);
    }
    else
    {
        root->right = insertNodePreorder(root->right, data);
    }
    return root;
}

node* create(node* root, int data)
{
    return(insertNodePreorder(root, data));
}

void printPre(node* root)
{
    if(root != NULL)
    {
        cout<<" "<<root->data;
        printPre(root->left);
        printPre(root->right);
    }   
}

int main()
{
    node* root = NULL;
    int pre[] = {10,5,1,7,40,50};
    int n = sizeof(pre)/sizeof(pre[0]);
    for(int i = 0; i<n; i++)
    {
        root = create(root, pre[i]);
    }
    printPre(root);
    return 0;
}