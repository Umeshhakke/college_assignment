/*Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

Examples:

Input : arr[] = {-8, 2, 3, -6, 10}, k = 2

Output : -8 0 -6 -6

First negative integer for each window of size k

{-8, 2} = -8

{2, 3} = 0 (does not contain a negative integer)

{3, -6} = -6

{-6, 10} = -6

 

Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3

Output : -1 -1 -7 -15 -15 0


Nmae: Umesh Pandit Hakke
Class S.Y (A)
Roll No: 2059
*/



#include <stdio.h>

void firstNegativeInWindows(int arr[], int n, int k) {
    int firstNegative[k];
    int front = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (i >= k && arr[i - k] < 0) {
            front++;
        }
        
        if (arr[i] < 0) {
            firstNegative[count++] = arr[i];
        }
        
        if (i >= k - 1) {
            if (count > front) {
                printf("%d ", firstNegative[front]);
            } else {
                printf("0 ");
            }
        }
    }
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the size of the window (k): ");
    scanf("%d", &k);

    printf("Output for the given array and window size:\n");
    firstNegativeInWindows(arr, n, k);
    printf("\n");

    return 0;
}

