/*
Link List : Check if link list is pailindrome
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

bool isPailindrome(node* head)
{
    stack<int> s;
    node* temp = head;
    while(temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        int i = s.top();
        s.pop();
        if(temp->data != i)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

int main()
{
    node* head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    //printList(head);
    //head->next->next->next->next = head;
    if(isPailindrome(head))
    {
        cout<<"Pailindrome\n";
    }
    else
    {
        cout<<"Not Pailindrome\n";
    }
    return 0;
}