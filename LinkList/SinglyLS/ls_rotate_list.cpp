/*
Rotate a Linked List

Given a singly linked list, rotate the linked list counter-clockwise by k nodes. 
Where k is a given positive integer. 
For example, if the given linked list is 10->20->30->40->50->60 and k is 4, 
the list should be modified to 50->60->10->20->30->40. 
Assume that k is smaller than the count of nodes in a linked list.
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

node* rotateList(node* head, int k)
{
    node* current = head;
    node* kthNode = NULL;
    int count = 0;

    while(current != NULL && count < k)
    {
        current = current->next;
        count++;
    }

    kthNode = current;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
    return head;
}

int main()
{
    node * head = NULL;
    head = push(head, 23);
    head = push(head, 37);
    head = push(head, 76);
    head = push(head, 91);
    head = push(head, 98);
    head = push(head, 100);

    printList(head);
    head = rotateList(head,3);
    printList(head);
    return 0;
}