/*

Replace each node in binary tree with the sum of its inorder predecessor and successor

Given a binary tree containing n nodes. The problem is to replace each node in the binary 
tree with the sum of its inorder predecessor and inorder successor.

Examples: 

Input :          1
               /   \
              2     3
            /  \  /  \
           4   5  6   7

Output :        11
              /    \
             9      13
            / \    /  \
           2   3   4   3
                  
For 1:
Inorder predecessor = 5
Inorder successor  = 6
Sum = 11

For 4:
Inorder predecessor = 0
(as inorder predecessor is not present)
Inorder successor  = 2
Sum = 2

For 7:
Inorder predecessor = 3
Inorder successor  = 0
(as inorder successor is not present)
Sum = 3


Approach:
Create an array arr. Store 0 at index 0. 
Now, store the inorder traversal of tree in the array arr. 
Then, store 0 at last index. 0’s are stored as inorder predecessor 
of leftmost leaf and inorder successor of rightmost leaf is not present. 

Now, perform inorder traversal and while traversing node replace node’s value 
with arr[i-1] + arr[i+1] and then increment i. 
In the beginning initialize i = 1. For an element arr[i], the values arr[i-1] and arr[i+1] 
are its inorder predecessor and inorder successor respectively.
*/

#include<iostream>
#include<vector>
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

void printPreorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void storeInorder(node* root, vector<int> &arr)
{
    if(root == NULL)
    {
        return;
    }

    storeInorder(root->left, arr);

    arr.push_back(root->data);

    storeInorder(root->right, arr);
}

void sumNodesAll(node* root, vector<int> arr, int *i)
{
    if(root == NULL)
    {
        return;
    }

    sumNodesAll(root->left, arr, i);
    root->data = arr[*i-1] + arr[*i+1];
    ++*i;
    sumNodesAll(root->right, arr, i);
}

void sumNodes(node* root)
{
    if(root == NULL)
    {
        return;
    }

    vector<int> arr;
    arr.push_back(0);
    //save inorder into vector
    storeInorder(root, arr);
    arr.push_back(0);
    int i = 1;
    sumNodesAll(root, arr, &i);
}

int main()
{
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    cout<<"\nPreorder : ";
    printPreorder(root);
    sumNodes(root);
    cout<<"\nPreorder : ";
    printPreorder(root);
    return 0;
}