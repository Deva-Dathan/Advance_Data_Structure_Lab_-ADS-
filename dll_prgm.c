#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

void insertAtBeg()
{
    int num;
    printf("Enter the value\n");
    scanf("%d", &num);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Value inserted\n");
}
void insertAtEnd()
{
    struct node *temp = head;
    struct node *newnode;
    int num;
    printf("Enter the value\n");
    scanf("%d", &num);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        newnode->prev = temp;
        printf("Value inserted\n");
    }
}
void insertAtPos()
{
    struct node *temp = head;
    int i, pos, num;
    printf("enter the position ");
    scanf("%d", &pos);
    printf("Enter the Value to be inserted");
    scanf("%d", &num);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        printf("list is empty");
    }
    for (i = 1; i < pos; i++)
    {
        if (temp->next == NULL)
        {
            printf("No position found");
        }
        else
        {
            temp = temp->next;
        }
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}
void deletelist()
{
    struct node *newnode, *temp;
    int loc, i;
    printf("\n Enter the location of the node after which you want to Delete: \n");
    scanf("%d", &loc);
    temp = head;
    if (head == NULL)
    {
        printf("List is Empty");
    }

    for (i = 0; i < loc; i++)
    {
        newnode = temp;
        temp = temp->next;

        if (temp == NULL)
        {
            printf("\nERROR");
            return;
        }
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    free(temp);
    printf("\nDeleted node-%d", loc + 1);
}
void search()
{
    struct node *temp = head;
    int num, flag = 0, i = 0;
    printf("Enter the element\n");
    scanf("%d", &num);
    if (head == NULL)
    {
        printf("list is empty");
    }
    while (temp->next != NULL)
    {
        if (temp->data == num)
        {
            break;
        }
        else
        {
            flag = 1;
        }
        i++;
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("\nElement found at position %d", i + 1);
    }
    else
    {
        printf("Element not found");
    }
}
void displaylist()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf("\t");
        temp = temp->next;
    }
}
int main()
{
    while (1)
    {

        int ch;
        printf("1.Insert At Begining\t2.Insert At End \t3.Insert At random  \t4.Search \t5.Delete \t6.Display \t7.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;
        case 4:
            search();
            break;
        case 5:
            deletelist();
            break;
        case 6:
            displaylist();
            break;
        case 7:
            printf("exited");
            exit(0);

        default:
            printf("Invalid Choice!");
        }
    }
    return 0;
}
