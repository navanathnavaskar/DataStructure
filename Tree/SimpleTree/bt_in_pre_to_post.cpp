/*
Given Inorder and Preorder traversal of tree, give postorder
*/

#include<iostream>
using namespace std;

int search(int in[], int x, int n)
{
    for(int i=0; i<n;i++)
    {
        if(in[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void printPost(int in[], int pre[], int n)
{
    int root = search(in, pre[0], n);

    //print left subtree
    if(root != 0)
    {
        printPost(in, pre + 1, root);
    }

    //print right subtree
    if(root != n-1)
    {
        printPost(in + root + 1, pre + root + 1, n - root - 1);
    }

    //print node
    cout<<" "<<pre[0];
}

int main()
{
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    printPost(in, pre, n);
    return 0;
}