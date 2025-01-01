/*
Nmae: Umesh Pandit Hakke
Class S.Y (A)
Roll No: 2059


Queue using array
*/
#include <stdio.h>

#define MAX 100  

int queue[MAX];  
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int value = queue[front];
        front++;
        if (front > rear) {  
            front = rear = -1;
        }
        printf("Dequeued: %d\n", value);
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contains: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Peek front item\n");
        printf("5. Exit\n");
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
                value = peek();
                if (value != -1) {
                    printf("Front item is: %d\n", value);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

