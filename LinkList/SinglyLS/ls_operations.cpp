
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
    int ch;
    int data;
    int index;
    while (ch != 9)
    {
        cout<<"\nLink List Operations : \n";
        cout<<"1. Insert Begining\n2. Insert End\n3. Insert Middle\n4. Delete Begining\n5. Delete End\n6. Delete Specific\n7. Display List\n8. Search in List\n9. Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"\nEnter data to be added : ";
            cin>>data;
            head = insertBegin(head, data);
            break;
        case 2:
            cout<<"\nEnter data to be added : ";
            cin>>data;
            head = insertEnd(head, data);
            break;
        case 3:
            cout<<"\nEnter data to be added : ";
            cin>>data;
            cout<<"\nEnter Index node data : ";
            cin>>index;
            head = insertMid(head, data, index);
            break;
        case 4:
            head = deleteFirst(head);
            break;
        case 5:
            head = deleteLast(head);
            break;

        case 6:
            cout<<"\nEnter data to be deleted : ";
            cin>>data;
            head = deleteMid(head, data);
            break;
        case 7:
            Display(head);
            break;
        case 8:
            cout<<"\nEnter data to be searched : ";
            cin>>data;
            if(searchElement(head, data))
            {
                cout<<"\nElement found in list.";
            }
            else
            {
                cout<<"\nElement not present in list.";
            }
            break;
        case 9:
            cout<<"\nExit from program...";
            break;
        default:
            cout<<"\nEnter valid choice.";
            break;
        }
    }
    
    return 0;
}
