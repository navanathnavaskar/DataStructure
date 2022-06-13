/* Link List : Remove duplicates from link list */

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

node* removeDuplicates(node* head)
{
    node* temp = head;
    
    node* next_next = NULL;
    while(temp->next != NULL)
    {
        if(temp->next->data == temp->data)
        {
            next_next = temp->next->next;
            free(temp->next);
            temp->next = next_next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    node * head = NULL;
    head = push(head, 39);
    head = push(head, 34);
    head = push(head, 34);
    head = push(head, 27);
    head = push(head, 14);
    head = push(head, 4);
    head = push(head, 4);

    printList(head);
    head = removeDuplicates(head);
    printList(head);
    return 0;
}