/*
Name:Umesh Pandit Hakke 
Class : S.Y (A)
Roll No: 2059

Program to implement Selection Sort
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, j;
    printf("Enter the size of data array: ");
    scanf("%d", &size);
    
    int data[size];
    printf("Enter the elements to the data array: \n");
    
    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }
    
   
    for (i = 0; i < size - 1; i++) {
        int min = i;
        for (j = i + 1; j < size; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        
        if (min != i) {
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
    
    printf("Sorted array: \n");
    for (i = 0; i < size; i++) {
        printf("%d\t", data[i]);
    }
    
    return 0;
}

