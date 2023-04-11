#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

int circularQueue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the circular queue is empty
int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if the circular queue is full
int isFull() {
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    else
        return 0;
}

// Function to enqueue an element into the circular queue
void enqueue(int item) {
    if (isFull()) {
        printf("Error: Circular Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    circularQueue[rear] = item;
    printf("%d has been enqueued\n", item);
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Error: Circular Queue is empty\n");
        return;
    } else if (front == rear) {
        printf("%d has been dequeued\n", circularQueue[front]);
        front = rear = -1;
    } else {
        printf("%d has been dequeued\n", circularQueue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to display the elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Elements in the circular queue: ");
    int i = front;
    while (i != rear) {
        printf("%d ", circularQueue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", circularQueue[rear]);
}

int main() {
    int choice, item;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
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
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
