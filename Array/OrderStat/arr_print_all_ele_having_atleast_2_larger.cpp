/*
Find all elements in array which have at-least two greater elements

Given an array of n distinct elements, the task is to find all elements in array 
which have at-least two greater elements than themselves.

Examples : 

    Input : arr[] = {2, 8, 7, 1, 5};
    Output : 2  1  5  
*/

/*
Method 1: use 2 loops: check if element has 2 greater numbers in array. 
if yes then we have to print element. 
*/

/*
Method 2: Sort array. print all n-2 elements. Except last two elements.  
*/

/*
Method 3: Find second max and then print all elements less than this element.
*/