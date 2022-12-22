#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* newNode(int data)
{
    Node* t = (Node*) malloc (sizeof(Node));
    t -> data = data;
    t->next = NULL;
    return t;
}

Node* push(Node* head, int data)
{
    Node* t = newNode(data);
    if(head == NULL)
    {
        head = t;
        return head;
    }
    t -> next = head;
    head =  t;
    return head;
}

void getNode(Node* head)
{
    map<Node*, int> m;
    int flag = 0;
    while(head != NULL)
    {
        if(m.find(head) != m.end())
        {
            flag = 1;
            cout<<"Loop Detected "<<head -> data<<endl;
            break;
        }
        m[head] = 1;
        head = head -> next;
    }
    if(flag == 0)
    {
        cout<<"No Loop Detected"<<endl;
    }
}

void printLS(Node* head)
{
    while(head != NULL)
    {
        cout<<" "<<head -> data;
        head = head -> next;
    }
}

int main()
{
    Node* head = newNode(1);
    head -> next = newNode(2);
    head -> next -> next = newNode(3);
    head -> next -> next -> next = newNode(4);
    head -> next -> next -> next -> next = head;
    //head = push(head, 6);
    //head = push(head, 5);
    //head = push(head, 4);
    //head = push(head, 3);
    //head = push(head, 2);
    //head = push(head, 1);
    //printLS(head);
    getNode(head);
    return 0;
}