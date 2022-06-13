/*
Decimal Equivalent of Binary Linked List

Given a singly linked list of 0s and 1s find its decimal equivalent.

   Input  : 0->0->0->1->1->0->0->1->0
   Output : 50   

   Input  : 1->0->0
   Output : 4
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

void binary_to_decimal(node* head)
{
    int res=0;
    while(head != NULL)
    {
        res = (res << 1) + head->data;

        head = head->next;
    }

    cout<<"Decimal equivalent : "<<res<<endl;
}

int main()
{
    node * head = NULL;
    head = push(head, 1);
    head = push(head, 1);
    head = push(head, 0);
    head = push(head, 1);

    printList(head);
    binary_to_decimal(head);
    return 0;
}