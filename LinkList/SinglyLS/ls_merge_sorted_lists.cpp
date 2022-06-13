/*
Reverse a linked list

Given pointer to the head node of a linked list, the task is to reverse the linked list.
We need to reverse the list by changing the links between nodes.

Examples: 

    Input: Head of following linked list 
    1->2->3->4->NULL 
    Output: Linked list should be changed to, 
    4->3->2->1->NULL
*/

#include <iostream>
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
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* push( node* head, int data)
{
    node* nNode = newNode(data);
    nNode->next = head;
    head = nNode;
    return head;
}

void printList(node * head)
{
    while(head != NULL)
    {
        cout<<head->data<<"--->";
        head = head->next;
    }
    cout<<endl;
}

node* reverseList(node* head)
{
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while(current != NULL)
    {
        cout<<"Nath "<<current->data<<endl;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

node* mergeSorted(node* a, node* b)
{
    node* res = NULL;
    if ( a == NULL && b == NULL)
    {
        return NULL;
    }
    else if(a == NULL)
    {
        res = reverseList(b);
        return res;
    }
    else if(b == NULL)
    {
        res = reverseList(a);
        return res;
    }
    
    //cout<<"Nath Here"<<endl;
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data)
        {
            res = push(res, a->data);
            a = a->next;
        }
        else
        {
            res = push(res, b->data);
            b = b->next;
        }
    }

    
    while(a != NULL)
    {
        res = push(res, a->data);
        a = a->next;
    }

    while(b != NULL)
    {
        res = push(res, b->data);
        b = b->next;
    }
    return res;
}

int main()
{
    node * head1 = NULL;
    head1 = push(head1, 91);
    head1 = push(head1, 67);
    head1 = push(head1, 41);
    head1 = push(head1, 7);

    node * head2 = NULL;
    head2 = push(head2, 81);
    head2 = push(head2, 77);
    head2 = push(head2, 32);
    head2 = push(head2, 1);

    printList(head1);
    printList(head2);
    node* head3 = NULL;
    head3 = mergeSorted(head1, head2);
    printList(head3);
    return 0;
}