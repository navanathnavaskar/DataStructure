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

node* insert(node* root, int data)
{
    if(root == NULL)
    {
        return(createNode(data));
    }

    node* temp = root;
    node* prev = NULL;
    while(temp)
    {
        if(data < temp->data)
        {
            prev = temp;
            temp = temp ->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if(data < prev->data)
    {
        prev->left = createNode(data);
    }
    else
    {
        prev->right = createNode(data);
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

node* getMinValueNode(node* root)
{
    node* curr = root;
    while(curr &&  curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node* deleteNode(node * root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    //if node in left of bst
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key >root->data) //node is in right BST
    {
        root->right = deleteNode(root->right, key);
    }
    else // node to be deleted is found
    {
        //check if node has no child or no left child
        if(root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = getMinValueNode(root->right);
        root->data = temp->data;
        //delete inorder successor 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
    deleteNode(root, 60);
    cout<<endl;
    printInorder(root);
    return 0;
}