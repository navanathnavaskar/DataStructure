/* Link List : Swap two nodes having matching value of data.
*/

#include<iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node* next;
};

typedef struct Node node;

node* newNode(int data)
{
    node* nNode = (node*) malloc(sizeof(node));

    nNode->data = data;
    nNode->next = NULL;
    return nNode;
}

node* push(node* head, int data)
{
    node* nNode = newNode(data);

    nNode->next = head;
    head = nNode;
    return head;
}


void printList(node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"--->";
        head = head->next;
    }
    cout<<endl;
}

node* swap2nodes(node* head, int x, int y)
{
    node* temp = head;
    
    node* px = NULL;
    node* cx = head;
    node* py = NULL;
    node* cy = head;

    while(cx && cx->data != x)
    {
        px = cx;
        cx = cx->next;
    }

    while(cy && cy->data != y)
    {
        py = cy;
        cy = cy->next;
    }

    if(cx == NULL or cy == NULL)
    {
        return head;
    }

    //if cx is head node
    if(px == NULL)
    {
        head = cy;
    }
    else
    {
        px->next = cy;
    }

    //if cy is head 
    if(py == NULL)
    {
        head = cx;
    }
    else
    {
        py->next = cx;
    }

    //swap next pointers
    node * t = cy->next;
    cy->next = cx->next;
    cx->next = t;

    return head;
}

int main()
{
    node * head = NULL;
    head = push(head, 39);
    head = push(head, 74);
    head = push(head, 34);
    head = push(head, 27);
    head = push(head, 14);
    head = push(head, 4);
    head = push(head, 44);

    printList(head);
    head = swap2nodes(head, 4, 34);
    printList(head);
    return 0;
}