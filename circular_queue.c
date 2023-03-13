#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() 
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    int data;
    printf("Enter The Value: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue() {
    struct node *temp = front;
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }
    printf("%d is removed from queue.\n", temp->data);
    free(temp);
}

void display() {
    struct node *temp = front;
    if(front == NULL) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Printing The List : ");
    while(temp->next != front) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main() {
    int choice, data;
    while(1) {
        printf("\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        printf("\nEnter The Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
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
}
