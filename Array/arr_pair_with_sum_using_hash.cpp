/*
Using hasmap to cehck if array has given sum pair

arr[] = {0, -1, 2, -3, 1} 
sum = -2 
Now start traversing: 
Step 1: For ‘0’ there is no valid number ‘-2’ so store ‘0’ in hash_map. 
Step 2: For ‘-1’ there is no valid number ‘-1’ so store ‘-1’ in hash_map. 
Step 3: For ‘2’ there is no valid number ‘-4’ so store ‘2’ in hash_map. 
Step 4: For ‘-3’ there is no valid number ‘1’ so store ‘-3’ in hash_map. 
Step 5: For ‘1’ there is a valid number ‘-3’ so answer is 1, -3 
*/

#include <iostream>
#include <unordered_set>
using namespace std;

void isSum(int a[], int n, int sum)
{
    unordered_set<int> s;

    for(int i = 0; i < n; i++)
    {
        int temp = sum - a[i];
        if(s.find(temp) != s.end())
        {
            cout<<"Found ("<<a[i]<<","<<temp<<") in array with given sum."<<endl;
        }
        
        s.insert(a[i]);
    }
}


int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 ,12};
	int n = 16;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Function calling
	isSum(A, arr_size, n);

	return 0;
}