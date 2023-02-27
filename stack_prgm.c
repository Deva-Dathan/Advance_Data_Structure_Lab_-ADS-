#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* top=NULL;
void InsertAtBeg_PUSH()
{
    int val;
    printf("Enter The Value:");
    scanf("%d",&val);
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
    printf("\n PUSH Operation Performed\n");
}

void DeleteAtBeg_POP()
{
    struct Node* temp=top;
    top=top->next;
    free(temp);
    printf("POP Operation Performed");
}

void display()
{
    struct Node* temp=top;
    printf("Values:");
    while(temp != NULL)
    {
        printf("%d",temp -> data);
        temp = temp->next;
    }
    printf("\n\n");
    
}
int main()
{
    while (1)
    {
    int ch;   
    printf("\n1.PUSH \t 2.POP \t 3.DISPLAY \t 4.Exit \n"); 
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        InsertAtBeg_PUSH();
        break;
    case 2:
        DeleteAtBeg_POP();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    default:
        printf("Invalid Choice...Enter a Valid Choice...");
    }
    }   
}