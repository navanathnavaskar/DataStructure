/* 
Segregate even and odd nodes in a Linked List

Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.
Examples: 

Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL
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

node* append(node* head, int data)
{
    node* nNode = newNode(data);
    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = nNode;
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

node* separateEvenOdd(node* head)
{
    node* currNode = head;
    node* evenStart = NULL;
    node* evenEnd = NULL;
    node* oddStart = NULL;
    node* oddEnd = NULL;

    while(currNode != NULL)
    {
        int val = currNode->data;

        if(val % 2 == 0) //even
        {
            if(evenStart == NULL) //empty EVEN list
            {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }
        else // Odd
        {
            if(oddStart == NULL)
            {
                oddStart = currNode;
                oddEnd = currNode;
            }
            else
            {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }
        currNode = currNode->next;
    }

    if(evenStart == NULL)
    {
        head = oddStart;
        return head;
    }
    if(oddStart == NULL)
    {
        head = evenStart;
        return head;
    }

    evenEnd->next = oddStart;
    head = evenStart;

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
    head = separateEvenOdd(head);
    printList(head);
    return 0;
}