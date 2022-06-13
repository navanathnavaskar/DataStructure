/*
Insertion Sort
 
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
Algorithm 
To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
Example: 

Another Example: 
12, 11, 13, 5, 6
Let us loop for i = 1 (second element of the array) to 4 (last element of the array)
i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12 
11, 12, 13, 5, 6
i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13 
11, 12, 13, 5, 6
i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position. 
5, 11, 12, 13, 6
i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position. 
5, 6, 11, 12, 13 

*/

#include<iostream>
using namespace std;

/*
Bubble Sort
 
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping 
the adjacent elements if they are in the wrong order.
Example: 
First Pass: 
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
Second Pass: 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
Now, the array is already sorted, but our algorithm does not know if it is completed. 
The algorithm needs one whole pass without any swap to know it is sorted.
Third Pass: 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 

*/
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<endl;
}

void insertionSort(int a[], int n)
{
    int key = 0;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        key = a[i];
        j = i-1;

        //make space for small element
        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j - 1;
        }

        //place element at correct position
        a[j+1] = key;
    }
}

int main()
{
    int arr[] = {84,65,62,28,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}