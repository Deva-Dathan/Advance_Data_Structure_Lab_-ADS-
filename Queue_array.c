#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = 0;
int rear = -1;

int isFull() {
    if (rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int element) {
    if (isFull())
        printf("Queue is full.\n");
    else {
        rear++;
        queue[rear] = element;
        printf("Enqueued element: %d\n", element);
    }
}

void dequeue() {
    if (isEmpty())
        printf("Queue is empty.\n");
    else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (isEmpty())
        printf("Queue is empty.\n");
    else {
        printf("Elements in the queue are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
