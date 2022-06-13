/*
Add two numbers represented by linked lists

Given two numbers represented by two lists, write a function that returns the sum list. 
The sum list is a list representation of the addition of two input numbers.

Example:

    Input: 
    List1: 5->6->3 // represents number 563 
    List2: 8->4->2 // represents number 842 
    Output: 
    Resultant list: 1->4->0->5 // represents number 1405 
*/

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
    node* current = head;
    node* prev = NULL;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

node* addLists(node* a, node* b)
{
    node* res = NULL;
    int carry = 0;
    int sum = 0;
    while(a != NULL && b != NULL)
    {
        sum = carry + a->data + b->data;
        carry = sum > 9 ? 1: 0;
        sum = sum % 10;

        res = push(res, sum);
        if(a)
            a=a->next;
        if(b)
            b=b->next;
    }
    
    while (a != NULL)
    {
        sum = carry + a->data;
        carry = sum > 9 ? 1: 0;
        sum = sum % 10;

        res = push(res, sum);
        a=a->next;
    }

    while (b != NULL)
    {
        sum = carry + b->data;
        carry = sum > 9 ? 1: 0;
        sum = sum % 10;

        res = push(res, sum);
        b=b->next;
    }
    return res;
}

int main()
{
    node * head1 = NULL;
    head1 = push(head1, 3);
    head1 = push(head1, 7);
    head1 = push(head1, 0);
    head1 = push(head1, 1);

    node * head2 = NULL;
    head2 = push(head2, 3);
    head2 = push(head2, 7);
    head2 = push(head2, 6);
    printList(head1);
    printList(head2);
    head1 = reverseList(head1);
    head2 = reverseList(head2);

    node* head = addLists(head1, head2);
    printList(head);
    return 0;
}