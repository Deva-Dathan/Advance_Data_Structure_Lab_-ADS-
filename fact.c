#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* create_node(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node** head, int value) {
    struct node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

void multiply_list(struct node* head, int n) {
    struct node* current_node = head;
    int carry = 0;
    while (current_node != NULL) {
        int product = current_node->value * n + carry;
        current_node->value = product % 10;
        carry = product / 10;
        current_node = current_node->next;
    }
    if (carry > 0) {
        insert_node(&head, carry);
    }
}

struct node* factorial(int n) {
    int i;
    struct node* result = create_node(1);
    for (i = 2; i <= n; i++) {
        multiply_list(result, i);
    }
    return result;
}

void print_list(struct node* head) {
    struct node* current_node = head;
    while (current_node != NULL) {
        printf("%d", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    struct node* result = factorial(n);
    printf("Factorial of %d is: ",result);
return 0;
}