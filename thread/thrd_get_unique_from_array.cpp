#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;

//struct for input to each thread
struct data
{
    int start; //start index for each thread
    int end; //end index for each thread
    int *arr; //pointer to first array element
};

//create map for storing frequency of each element
map<int, int> mp;
//create mutex lock
pthread_mutex_t lock1;

void* func(void* arg)
{
    //request lock first
    pthread_mutex_lock(&lock1);
    //get data
    struct data* ptr = (struct data*) arg;
    //process array elements
    for(int i = ptr->start  ; i <= ptr->end; i++)
    {
        //create iterator 
        map<int, int> :: iterator it;
    
        // if element not in map then initialize it to 0 else increment frequency count
        if (mp.find(ptr->arr[i]) == mp.end())
        {
            mp[ptr->arr[i]] = 1;
        }
        else
        {
            mp[ptr->arr[i]]++;
        }
    }
    // release lock
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void find_unique_numbers(int arr[], int N, int T)
{
    //create array of threads of size T
    pthread_t threads[T];

    int spos = 0;
    int epos = spos + (N/T) - 1;
    for(int i = 0; i < T; i++)
    {
        //create data for thread
        struct data* dptr = (struct data*) malloc(sizeof(struct data));
        dptr -> start = spos;
        dptr -> end = epos;
        dptr -> arr = arr;

        //create thread
        int a = pthread_create(&threads[i], NULL, func, (void*) dptr);

        //update spos and npos
        spos = epos + 1;
        epos = spos + (N/T) - 1;
        if(i == T-1)
        {
            epos = N-1;
        }
    }

    // waiting for threads to join
    for(int i = 0; i< T; i++)
    {
        int rc = pthread_join(threads[i], NULL);
    }
    //print unique
    for(auto it: mp)
    {
        if(it.second == 1)
        {
            cout<<" "<<it.first;
        }
        cout<<endl;
    }
}

int main()
{
    // initialize mutex lock
    pthread_mutex_init(&lock1, NULL);
    int T = 3;
    int arr[] = {1,1,3,67,23,67,55,2,55};
    int n = sizeof(arr)/sizeof(arr[0]);
    find_unique_numbers(arr,n, T);
    return 0;
}