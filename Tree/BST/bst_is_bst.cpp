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

int isBSTMain(node* root, int min, int max)
{
    //cout<<"Min = "<<min<<" Max = "<<max<<endl;
    if(root == NULL)
        return 1; // Empty node is BST

    if(root->data < min || root->data > max)
        return 0; 

    return (isBSTMain(root->left, min, root->data - 1) && isBSTMain(root->right, root->data+1, max));
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
    if(isBSTMain(root, INT_MIN, INT_MAX))
    {
        cout<<"\nBST";
    }
    else
    {
        cout<<"\nNot BST";
    }
    return 0;
}