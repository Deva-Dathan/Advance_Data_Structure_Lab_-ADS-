#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void deleteList(Node** headRef) {
    Node* current = *headRef;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *headRef = NULL;
}

void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* multiplyList(Node* head, int num) {
    Node* result = NULL;
    Node* tail = NULL;
    int carry = 0;

    while (head != NULL) {
        int product = head->data * num + carry;
        carry = product / 10;
        product = product % 10;

        Node* newNode = createNode(product);

        if (result == NULL) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        head = head->next;
    }

    if (carry > 0) {
        Node* newNode = createNode(carry);
        tail->next = newNode;
        tail = newNode;
    }

    return result;
}

Node* factorial(int n) {
    int i;
    Node* result = createNode(1);

    for (i = 2; i <= n; i++) {
        Node* temp = result;
        result = multiplyList(result, i);
        deleteList(&temp);
    }

    return result;
}

int main() {
    int n;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    Node* result = factorial(n);
    printf("Factorial of %d is: ", n);
    printList(result);
    deleteList(&result);

    return 0;
}
