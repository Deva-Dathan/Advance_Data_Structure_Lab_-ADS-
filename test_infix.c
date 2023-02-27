#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE-1) {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow");
        return -1;
    }
    return stack[top--];
}

int symbols(char operator) {
    if (operator == '^') {
        return 3;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '+' || operator == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix, ")");

    i = 0;
    j = 0;
    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix[j] = item;
            j++;
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        } else {
            while (symbols(stack[top]) >= symbols(item)) {
                postfix[j] = pop();
                j++;
            }
            push(item);
        }
        i++;
        item = infix[i];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter Infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s", postfix);

    return 0;
}
