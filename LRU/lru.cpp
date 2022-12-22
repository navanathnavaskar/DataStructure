#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        // get value in O(1) time from q
        int val = (mp[key]) -> second;

        dq.erase(mp[key]); //remove element from q as it is most recently used

        //add elemt to front of q
        dq.push_front(make_pair(key,val));
        //update key and iterator to map
        mp[key] = dq.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(get(key) == value)
            return;
        //get data from cache
        cout<<"\n Key = "<<key<<" val = "<<value;
        if(mp.find(key) == mp.end())
        {
            cout<<"\nHere q size = "<<dq.size()<<" capacity = "<<capacity;
            // data not found in cache
            //check if cache is full
            /*
                if key not found in cache then there are 2 posibilities
                1. cache is full
                    a. Least recently used element is at end of queue(rear)
                    b. get key for this element from rear of q
                    c. delete this element from q
                    d. erase this key from map
                    e. Now add new (key, value) pair at front of q
                    f. add key and iterator (dq.begin()) in map
                    g. Done
                2. cache is not full
                    a. Now add new (key, value) pair at front of q
                    b. add key and iterator (dq.begin()) in map
                    c. Done
            */
            if(dq.size() == capacity)
            {
                //cache full hence delete element 
                // from rear
                int last = dq.back().first;
                dq.pop_back();
                mp.erase(last);
                cout<<"put "<<key<<" "<<value<<" remove key = "<<last;
            }
        }
        else
        {
            // data found in cache
            /*
                If data present in cache then:
                1. erase data from queue using iterator stored in map
                2. Now add new (key, value) pair at front of q
                3. add key and iterator (dq.begin()) in map
                4. Done
            */
            dq.erase(mp[key]);
        }
        // add new element at front
        dq.push_front(make_pair(key, value));
        mp[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */