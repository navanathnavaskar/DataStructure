#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node * next;
};

Node* newNode(int data)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp -> next = NULL;
    return temp;
}

void pushNode(Node** head, int data, int &len)
{
    Node * temp = newNode(data);
    temp -> next = *head;
    *head = temp;
    len++;
}

Node* reverseLS(Node* head, int k, int len)
{
    //get stack
    stack<Node*> s;
    Node* curr = head;
    Node* prev = NULL;
    int totalCount = 0;
    while(curr != NULL)
    {
        if(totalCount + k > len)
        {
            while(curr != NULL)
            {
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
            break;
        }
        
        int count = 0;
        while(curr != NULL && count < k)
        {
            s.push(curr);
            curr = curr ->next;
            count++;
        }
        totalCount += k;
        
        while(! s.empty())
        {
            if(prev == NULL)
            {
                prev = s.top();
                head = prev;
                s.pop();
            }
            else
            {
                prev -> next = s.top();
                prev = prev -> next;
                s.pop();
            }
        }
    }
    prev->next = NULL;
    return head;
}

void printLS(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    Node* head = newNode(7);
    int len = 1;
    pushNode(&head, 6, len);
    pushNode(&head, 5, len);
    pushNode(&head, 4, len);
    pushNode(&head, 3, len);
    pushNode(&head, 2, len);
    pushNode(&head, 1, len);
    cout<<"Len = "<<len<<endl;
    printLS(head);
    head = reverseLS(head, 4, len);
    printLS(head);

    return 0;
}