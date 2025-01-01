/*
Nmae: Umesh Pandit Hakke
Class S.Y (A)
Roll No: 2059

Circular Queue using array
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *queue;
int front = -1;
int rear = -1;
int MAX;

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
bool isFull() {
    return (rear + 1) % MAX == front;
}

// Function to add an element to the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove an element from the circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) { // If the queue is now empty
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("Dequeued: %d\n", value);
        return value;
    }
}

// Function to display the elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (true) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Main function to demonstrate circular queue operations
int main() {
    printf("Enter the size of the circular queue: ");
    scanf("%d", &MAX);
    
    queue = (int *)malloc(MAX * sizeof(int)); // Dynamically allocate memory for the queue

    int choice, value;

    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free(queue); // Free the allocated memory for the queue
    return 0;
}

