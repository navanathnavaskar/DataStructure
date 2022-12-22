#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> arr;
    map<int, int> m;    
public:
    RandomizedSet() {    }
    
    bool insert(int val) {
        // check if element present in ds
        if(m.find(val) == m.end())
        {
            int index = arr.size();
            //add element as already not present
            arr.push_back(val);
            // add to map
            m[val] = index;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end())
        {
            return false;
        }
        int index = m[val];
        m.erase(val);
        int last = arr.size() - 1;
        swap(arr[last], arr[index]);
        arr.pop_back();

        //update map
        m.at(arr[index]) = index;
        return true;
    }
    
    int getRandom() {
        srand (time(NULL));
        int rindex = rand() % arr.size();
        return(arr[rindex]); 
    }
};