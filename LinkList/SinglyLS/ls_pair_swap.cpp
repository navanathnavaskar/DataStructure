/*
Pairwise swap elements of a given linked list

Given a singly linked list, write a function to swap elements pairwise. 

    Input : 1->2->3->4->5->6->NULL 
    Output : 2->1->4->3->6->5->NULL

    Input : 1->2->3->4->5->NULL 
    Output : 2->1->4->3->5->NULL

    Input : 1->NULL 
    Output : 1->NULL 
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

void swap(int * a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

node* swappair(node* head)
{
    node* temp = head;
        
    while(temp && temp->next != NULL)
    {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
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
    head = swappair(head);
    printList(head);
    return 0;
}