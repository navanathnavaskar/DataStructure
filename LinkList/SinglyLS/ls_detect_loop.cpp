/*
Link List : Detect loop from the link list 
*/
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
    node* temp = newNode(data);
    temp->next = head;
    head = temp;
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


//Loop detection using set.
//If set has current node in it then it is cycle.
bool isLoopSet(node* head)
{
    unordered_set<node*> s;
    
    while(head != NULL)
    {
        if(s.find(head) != s.end())
            return true;
            
        s.insert(head);
        head = head->next;
    }
    return false;
}

//Floyd'S cycle finding algorithm
//use 2 pointers slow pointer and fast pointer. 
//Slow pointer will move by 1 node and fast pointer by 2
// if cycle is there then they will meet at same point after some iterations.
int isLoop(node* head)
{
    node* slowptr = head;
    node* fstptr = head;
    if(head == NULL)
    {
        return 0;
    }
    
    while(slowptr && fstptr && fstptr->next!= NULL)
    {
        slowptr = slowptr->next;
        fstptr = fstptr->next->next;
        //cout<<"\nData "<<slowptr->data<<" "<<fstptr->data;
        if(slowptr == fstptr)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    node* head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    //printList(head);
    //head->next->next->next->next = head;
    if(isLoopSet(head))
    {
        cout<<"Loop Detected in Link List\n";
    }
    else
    {
        cout<<"No loop detected in list\n";
    }
    return 0;
}