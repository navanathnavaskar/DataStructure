/*

Deletion In A Binary Tree

Algorithm 
1. Starting at the root, find the deepest and rightmost node in binary tree and node which we want to delete. 
2. Replace the deepest rightmost node’s data with the node to be deleted. 
3. Then delete the deepest rightmost node.

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
    node* temp = (node*) malloc (sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insertNode(node* root, int data)
{
    if(root == NULL)
    {
        node * temp = createNode(data);
        root = temp;
        return root;
    }

    queue<node*> q;
    q.push(root);
    while(! q.empty())
    {
        node * temp = q.front();
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
    {
        return;
    }

    printInorder(root->left);
    cout<<" "<<root->data;
    printInorder(root->right);
}

void deleteDepest(node* root, node* d_node)
{
   queue<node*> q;
   q.push(root);

    node* temp;
   while(!q.empty())
   {
       temp = q.front();
       q.pop();

       if(temp == d_node)
       {
           temp = NULL;
           delete(d_node);
           return;
       }

        if(temp->left)
        {
            if(temp->left == d_node)
            {
                temp->left = NULL;
                delete(d_node);
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }

        if(temp->right)
        {
            if(temp->right == d_node)
            {
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
   }
}

node* deleteNode(node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL )
    {
        if(root->data == key)
        {
            delete(root);
            return NULL;
        }
        else
        {
            return root;
        }
    }
    queue<node*> q;
    q.push(root);
    node* temp = NULL; //depest node
    node* key_node = NULL; //node to delete
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == key)
        {
            key_node = temp;
        }

        if(temp->left != NULL)
        {
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    if(key_node != NULL)
    {
        int x = temp->data;
        //delete node
        deleteDepest(root, temp);
        //set data of key_node
        key_node->data = x;
    }
    return root;
}

int main()
{
    node* root =NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    cout<<"\nInorder Traversal : ";
    printInorder(root);
    root = deleteNode(root, 30);
    cout<<"\nInorder Traversal : ";
    printInorder(root);
    return 0;
}