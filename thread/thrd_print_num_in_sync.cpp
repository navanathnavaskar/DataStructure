#include<bits/stdc++.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

volatile int cnt = 0;
//create lock
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t *cond = NULL;

int threads;
void* func(void* arg)
{
    //get turn
    int turn = *(int*) arg;
    while(1)
    {
        //request lock
        pthread_mutex_lock(&lock1);
        //check if thread can enter critical section
        if(turn != cnt)
        {
            //not correct thread hence put every 
            //other thread in waiting state
            pthread_cond_wait(&cond[turn], &lock1);
        }
        //now print turn
        cout<<" "<<turn + 1;
        //find which thread to schedule next
        if(cnt < threads - 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        //wake up next thread
        pthread_cond_signal(&cond[cnt]);
        //unlock mutex
        pthread_mutex_unlock(&lock1);
    }
    return NULL;
}

int main()
{
    cout<<"\nEnter number of threads : ";
    cin>>threads;
    //create all threads
    pthread_t tid[threads];
    volatile int i;
    int arr[threads];
    cond = (pthread_cond_t*) malloc(sizeof(pthread_cond_t)*threads);
    //initialize conditions for all threads
    for(int i = 0; i<threads; i++)
    {
        if(pthread_cond_init(&cond[i], NULL) != 0)
        {
            cout<<"Error in condition init\n";
            exit(1);
        }
    }

    //create thread
    for(int i = 0; i<threads; i++)
    {
        arr[i] = i;
        pthread_create(&tid[i], NULL, func, (void*)&arr[i]);
    }

    //waiting for thread
    for(int i = 0; i<threads; i++)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}