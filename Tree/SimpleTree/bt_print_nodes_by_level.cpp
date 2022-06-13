#include<iostream>
#include<queue>
#include<limits.h>

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

void printLevelWise(node* root)
{
    int nc = 0;
    queue<node*> q;
    q.push(root);
    int max;
    while(1)
    {
        nc = q.size();

        if(nc == 0)
            break;
        
        max = INT_MIN;

        while(nc--)
        {
            node* front = q.front();
            q.pop();
            if(max < front->data)
                max = front->data;

            if(front->left)
            {
                q.push(front->left);
            }

            if(front->right)
            {
                q.push(front->right);
            }
        }
        cout<<max<<endl;
    }
}

int main()
{
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
 
    printLevelWise(root);
    return 0;
}