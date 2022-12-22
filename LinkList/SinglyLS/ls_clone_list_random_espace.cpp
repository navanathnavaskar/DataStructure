#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> mp;
        Node* temp, *newHead;

        //duplicate first node
        temp = head;
        newHead = new Node(temp->val);
        mp[temp] = newHead;

        // create new list and store mapping of old 
        // node to new node in map as key and value 
        while(temp -> next != NULL)
        {
            newHead -> next = new Node(temp->next->val);
            newHead = newHead -> next;
            temp = temp -> next;
            mp[temp] = newHead;
        }

        // Now copy ranrom pointers
        temp = head;

        while(temp != NULL)
        {
            // new node random will point to random node copy of new list
            mp[temp] -> random = mp[temp->random];
            temp = temp -> next;
        }
        // return new head
        return mp[head];
    }
}