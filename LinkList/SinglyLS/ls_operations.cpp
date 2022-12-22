/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node* newNode(int data)
{
    //memory allocation
    struct Node* temp = (node*)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

node* insertBegin(node* head, int data)
{
    //Create new node
    node* nNode = newNode(data);
    // Check if this is first node
    if (head == NULL)
    {
        head = nNode;
        return head;
    }
    nNode->next = head;
    head = nNode;
    return head;
}

node* insertEnd(node* head, int data)
{
    node* nNode = newNode(data);
    node* tmp = head;
    while(tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp->next = nNode;
    return head;
}

void Display(node* head)
{
    if(head == NULL)
    {
        cout<<"List is empty\n";  
    }
    node* temp = head;
    while(temp != NULL)
    {
        cout<<" -> "<<temp->data;
        temp = temp -> next;
    }
}

bool searchElement(node* head, int data)
{
    if(head == NULL)
        return false;
    
    node* temp = head;
    while(temp != NULL)
    {
        if(temp -> data == data)
            return true;
        temp = temp -> next;
    }
    return false;
}

int main()
{
    node* head = NULL;
    Display(head);
    head = insertBegin(head, 5);
    //Display(head);
    head = insertBegin(head, 10);
    head = insertBegin(head, 15);
    head = insertBegin(head, 20);
    head = insertBegin(head, 25);
    head = insertEnd(head, 100);
    Display(head);
    int element;
    cout<<"\nEnter element to be searched : ";
    cin>>element;
    
    if(searchElement(head, element))
    {
        cout<<"\nElement found in the list.\n";
    }
    else
    {
        cout<<"Element not found in the list\n";
    }
    return 0;
}
