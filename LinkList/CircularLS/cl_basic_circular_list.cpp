/*
Circular Link List Implementation
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node;

node* newNode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* push(node* head, int data)
{
    node* temp = newNode(data);

    if(head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        node* temp1 = head;
        while(temp1->next != head)
        {
            temp1 = temp1->next;
        }
        temp->next = head;
        temp1->next = temp;
    }
    return head;
}

void printList(node* head)
{
    node* temp = head;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    do
    {
        cout<<temp->data<<"--->";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

node* deleteNode(node* head, int k)
{
    node* curr = head;
    node* prev = NULL;

    while(curr->data != k)
    {
        if(curr->next == head)
        {
            cout<<"No node Found in list"<<endl;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL && curr->next == head) //only node
    {
        head = NULL;
        free(curr);
        return head;
    }

    //if last node
    if(curr->next == head && prev != NULL)
    {
        prev->next = head;
        free(curr);
        return head;
    }

    if(prev == NULL && curr->next != head) //first node but not only node
    {
        node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        head = curr->next;
        temp->next = head;
        
        free(curr);
        return head;
    }

    if(prev != NULL && curr->next != head) //middle node
    {
        prev->next = curr->next;
        free(curr);
        return head;
    }
    return head;
}

int main()
{
    node* head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);
    head = push(head, 40);
    head = push(head, 50);
    printList(head);
    head = deleteNode(head, 60);
    printList(head);
    return 0;
}