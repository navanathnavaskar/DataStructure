/*
Reverse a Linked List in groups of given size

Given a linked list, write a function to reverse every k nodes (where k is an input to the function). 

Example: 

    Input: 1->2->3->4->5->6->7->8->NULL, K = 3 
    Output: 3->2->1->6->5->4->8->7->NULL 
    Input: 1->2->3->4->5->6->7->8->NULL, K = 5 
    Output: 5->4->3->2->1->8->7->6->NULL 
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

node* reverseListInGrp(node* head, int k)
{
    if(head == NULL)
    {
        return NULL;
    }
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    int count = 0;

    while(current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next != NULL)
    {
        head->next = reverseListInGrp(next, k);
    }
    return prev;
}

int main()
{
    node * head = NULL;
    head = push(head, 23);
    head = push(head, 37);
    head = push(head, 76);
    head = push(head, 91);
    head = push(head, 32);

    printList(head);
    head = reverseListInGrp(head, 2);
    printList(head);
    return 0;
}