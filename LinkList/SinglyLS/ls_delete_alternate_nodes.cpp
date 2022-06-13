/*
Delete alternate nodes of a Linked List

Given a Singly Linked List, starting from the second node delete all alternate nodes of it. 
For example, if the given linked list is 1->2->3->4->5 then your function should convert it to 1->3->5, 
and if the given linked list is 1->2->3->4 then convert it to 1->3.
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

node* deleteAlt(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    node* prev = head;
    node* current = head->next;
    
    while(current != NULL && prev != NULL)
    {
        prev->next = current -> next;

        free(current);

        prev = prev->next;

        if(prev != NULL)
        {
            current = prev->next;
        }
    }

    return head;
}

int main()
{
    node * head = NULL;
    head = push(head, 23);
    head = push(head, 37);
    head = push(head, 76);
    head = push(head, 91);

    printList(head);
    head = deleteAlt(head);
    printList(head);
    return 0;
}