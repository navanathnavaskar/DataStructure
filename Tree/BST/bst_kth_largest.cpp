#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node node;

node* createNew(int data)
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
        root = createNew(data);
        return root;
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
        cout<<root->data<<"-->";
        printInorder(root->right);
    }
}

void findKthLarge(node* root, int k, int &c)
{
    if(root == NULL || c >= k)
    {
        return;
    }
    
    findKthLarge(root->right, k, c);
    c++;
    if(c == k)
    {
        cout<<k<<" th Largest = "<<root->data<<endl;
    }
    findKthLarge(root->left, k, c);
}

int main()
{
    node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 60);
    root = insert(root, 50);
    cout<<"Inorder : ";
    printInorder(root);
    cout<<endl;
    int c = 0;
    findKthLarge(root, 2, c);
    cout<<endl;
    return 0;
}