#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define max_size 50

char stack[max_size];
int top = -1;
void push(char item) 
{
    if (top >= max_size-1) 
    {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = item;
}
char pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow");
        return -1;
    }
    return stack[top--];
}
int symbols(char operator) 
{
    if (operator == '+' || operator == '-') 
    {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    } else {
        return 0;
    }
}
void conversion(char infix[], char postfix[]) {
    int i=0, j=0;
    char item,x;
    push('(');
    strcat(infix, ")");
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
    char infix[max_size], postfix[max_size];
    printf("Enter The Infix expression:");
    gets(infix);
    conversion(infix, postfix);
    printf("Postfix Expression: %s", postfix);
    return 0;
}