#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

typedef struct Node node;

node* mergeTree(node* t1, node* t2)
{
    //if t1 is null return t2
    if(!t1)
        return t2;
    if(!t2)
        return t1;

    //add t1 and t2 root
    t1 -> data = t1->data + t2->data;
    t1->left = mergeTree(t1->left, t2->left);
    t2->right = mergeTree(t1->right, t2->right);

    return t1;
}

void printInorder(node* root)
{
    if(root != NULL)
    {
        printInorder(root->left);
        cout<<" "<<root->data;
        printInorder(root->right);
    }
}

int main()
{
    node* root1 = new Node(10);
    root1 -> left = new Node(7);
    root1 -> right = new Node(20);
    root1 -> left -> left = new Node(4);
    root1 -> left -> right = new Node(8);
    printInorder(root1);
    cout<<endl;
    node* root2 = new Node(40);
    root2 -> left = new Node(30);
    root2 -> right = new Node(50);
    root2 -> left -> left = new Node(20);
    root2 -> right -> right = new Node(60);
    printInorder(root2);
    cout<<endl;
    
    root1 = mergeTree(root1, root2);
    printInorder(root1);
    cout<<endl;
    return 0;
}