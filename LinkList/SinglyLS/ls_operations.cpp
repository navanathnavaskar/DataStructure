
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

node* insertMid(node* head, int data, int index)
{
    //Create new node
    node* nNode = newNode(data);
    node* temp = head;
    while(temp -> data != index)
    {
        temp = temp -> next;
    }
    nNode -> next = temp -> next;
    temp -> next = nNode;
    return head;
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

node* deleteFirst(node* head)
{
    if (head == NULL)
        return NULL;
    node* temp = head;
    head = temp -> next;
    temp -> next = NULL;
    free(temp);
    return head;
}

node* deleteLast(node* head)
{
    if(head == NULL)
        return NULL;
    node* temp = head;
    node* q = head;
    while(temp -> next != NULL)
    {
        q = temp;
        temp = temp -> next;
    }
    q -> next = NULL;
    free(temp);
    return head;
}

node* deleteMid(node* head, int index)
{
    if(head == NULL)
        return NULL;
    node* temp = head;
    node* q = head;
    while(temp && temp -> data != index)
    {
        q = temp;
        temp = temp -> next;
    }
    if(temp != NULL)
    {
        q -> next = temp -> next;
        temp -> next = NULL;
        free(temp);
    }
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
    cout<<endl;
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
    head = insertMid(head, 200, 15);
    Display(head);
    head = deleteMid(head, 300);
    Display(head);
    
    /*
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
    */
    return 0;
}
