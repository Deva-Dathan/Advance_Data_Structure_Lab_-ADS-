#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int i,front = 0,rear = -1;

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
        printf("\nQueue is full.\n");
    else {
        rear++;
        queue[rear] = element;
        printf("\nEnqueued element: %d\n", element);
    }
}

void dequeue() {
    if (isEmpty())
        printf("Queue is empty.\n");
    else {
        printf("\nDequeued element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (isEmpty())
        printf("Queue is empty.\n");
    else {
        printf("\nElements in the queue are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter The Element To Be Enqueued: ");
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
                printf("Invalid choice....Enter a Valid Choice\n");
        }
    }

    return 0;
}
