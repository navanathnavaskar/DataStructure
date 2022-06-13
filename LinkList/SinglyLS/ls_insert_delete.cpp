/* Link List: Insert element in link list */

/* Simple Link List */

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node * next;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node ));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* deleteNode(struct Node* head, int data)
{
    struct Node* temp = head, *prev;
    //search node
    //if this is first node then
    if(temp -> data == data && temp != NULL)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp != NULL)
    {
        if(temp->data == data)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout<<"No data found";
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

struct Node* insertBegin(struct Node* head, int data)
{
    //Create new Node
    struct Node* nNode = newNode(data);
    //Point new node with head
    nNode->next = head;
    //Set new head
    head = nNode;
    return head;
}

struct Node* append(struct Node* head, int data)
{
    //Create new Node
    struct Node* nNode = newNode(data);
    struct Node* temp = head;
    //go to end 
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = nNode;
    return head;
}

// Insert after given data Node
struct Node* insert(struct Node* head, int sData, int nData)
{
    struct Node* nNode = newNode(nData);
    struct Node* temp = head;
    int flag = 0;
    while(temp != NULL)
    {
        if(temp->data == sData)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    
    if(flag == 1)
    {
        //data found
        nNode->next = temp->next;
        temp->next = nNode;
    }
    else
    {
        cout<<"No Data found."<<endl;
    }
    return head;
}

void printList(struct Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<"--->";
        node = node->next;
    }
    cout<<endl;
}

int getLengthRec(struct Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getLengthRec(head->next);
    }
}

int getLength(struct Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> next;
    }
    return count;
}

void printNthNodeFromLast(struct Node* head, int n)
{
    static int i = 0;
    if(head == NULL)
        return;
    printNthNodeFromLast(head->next, n);
    
    if(++i == n)
    {
        cout<<"\nNth Node from Last is: "<<head->data<<endl;
    }
}

void printMiddleNode(struct Node* head)
{
    struct Node* slw_ptr = head;
    struct Node* fst_ptr = head;
    
    if(head != NULL)
    {
        while(fst_ptr != NULL && fst_ptr->next != NULL)
        {
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next->next;
        }
        cout<<"Middile Node Data is: "<<slw_ptr->data<<endl;
    }
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
    cout<<"Link List before insert: ";
    printList(head);
    head = insertBegin(head, 21);
    cout<<"Link List after insert: ";
    printList(head);
    //append to List
    head = append(head, 31);
    cout<<"Link list after appending node : ";
    printList(head);
    head = insert(head, 1, 41);
    cout<<"Link list after inserting data: ";
    printList(head);
    head = insert(head, 31, 51);
    cout<<"Link list after inserting data: ";
    printList(head);
    
    head = deleteNode(head, 51);
    cout<<"List after deleteing : ";
    printList(head);
    cout<<"Length of List : "<<getLengthRec(head);
    printNthNodeFromLast(head, 2);
    printMiddleNode(head);
    return 0;
}