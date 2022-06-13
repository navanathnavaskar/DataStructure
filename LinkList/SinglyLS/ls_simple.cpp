/* Simple Link List */

#include<iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node * next;
};

void printList(Node *head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"--->";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    struct Node * head = NULL;
    struct Node * first = NULL;
    struct Node * second = NULL;

    //allocate space
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    
    first->data = 1;
    second->data = 2;
    head = first;
    first->next = second;
    printList(head);
    return 0;
}
