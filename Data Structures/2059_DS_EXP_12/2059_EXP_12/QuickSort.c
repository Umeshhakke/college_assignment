/*
Name : Umesh Pandit Hakke
Roll No: 2059
Class : S.Y (A) S4
Quick Sort
*/
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (array[j] < pivot) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[low], &array[i - 1]);
    return (i - 1);
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

int main() {
    int size;
    printf("Enter how many elements you want to enter: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements to array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    printf("Sorted elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }

    return 0;
}

