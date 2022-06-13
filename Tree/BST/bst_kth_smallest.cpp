#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};

typedef struct Node node;

node* createNew(int data)
{
    node* temp = (node*) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    return temp;
}

node* insert(node* root, int data)
{
    if(root == NULL)
    {
        return(createNew(data));
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

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);
    }
}
int count = 0;
void kth_smallest(node* root, int k)
{
    if(root == NULL)
    {
        return;
    }

    kth_smallest(root->left, k);
    count++;
    if(k == count)
    {
        cout<<k<<" th smallest : "<<root->data<<endl;
    }
    kth_smallest(root->right, k);
}

int main()
{
    node* root = createNew(30);
    root = insert(root, 10);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 42);
    kth_smallest(root, 3);
    return 0;
}