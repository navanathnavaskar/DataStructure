/* Link List : Remove duplicates from link list */
#include<bits/stdc++.h>
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
    
    node* prev = NULL;
    unordered_set<int> seen;

    while(temp != NULL)
    {
        cout<<"\nData = "<<temp->data<<endl;
        if(seen.find(temp->data) != seen.end())
        {
            prev->next = temp->next;
            free(temp);
            temp = prev;
        }
        else
        {
            prev = temp;
            seen.insert(temp->data);
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    node * head = NULL;
    head = push(head, 39);
    head = push(head, 14);
    head = push(head, 34);
    head = push(head, 4);
    head = push(head, 14);
    head = push(head, 4);
    head = push(head, 24);

    printList(head);
    head = removeDuplicates(head);
    printList(head);
    return 0;
}