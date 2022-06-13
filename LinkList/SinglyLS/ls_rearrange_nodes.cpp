/*
Rearrange a given linked list in-place.

Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. 
Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
You are required to do this in place without altering the nodes’ values. 

Examples: 

Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3
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
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

node* rearrange(node* head)
{
    //1. First find middle
    node* fast = head, *slow = head;
    node* curr = head;
    node* head1 = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //2. Create 2 lists
    node* head2 = slow->next;
    slow->next = NULL;
    
    //3. Reverse second list
    head2 = reverseList(head2);

    head = newNode(0);//dummy node
    curr = head;

    while(head1 || head2)
    {
        if(head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if(head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    return head->next; //skip dummy node
}

int main()
{
    node * head = NULL;
    head = push(head, 33);
    head = push(head, 43);
    head = push(head, 23);
    head = push(head, 37);
    head = push(head, 76);
    head = push(head, 91);

    printList(head);
    node* head3 = rearrange(head);
    printList(head3);
    return 0;
}