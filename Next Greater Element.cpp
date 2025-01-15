#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to find the next greater element for each element in the array
void nextGreaterElement(int arr[], int n) {
    // Stack to store elements
    int stack[MAX];
    int top = -1;
    
    // Traverse the array from right to left
    for (int i = n-1; i >= 0; i--) {
        // Pop elements from the stack that are smaller than or equal to the current element
        while (top != -1 && stack[top] <= arr[i]) {
            top--;
        }
        
        // If stack is not empty, then the top element is the next greater element
        if (top != -1) {
            printf("Next Greater Element for %d is %d\n", arr[i], stack[top]);
        } else {
            printf("Next Greater Element for %d is None\n", arr[i]);
        }
        
        // Push the current element onto the stack
        stack[++top] = arr[i];
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Next Greater Element for each element in the array:\n");
    nextGreaterElement(arr, n);
    
    return 0;
}
