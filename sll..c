#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertatfront()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter Value To Insert At Beginning:");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
    }
}
void insertatEnd()
{
    int data;
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Value To Insert At End:");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insertbyPosition()
{
    int loc, data, i;
    struct node *prev, *temp, *newnode;
    temp = prev = head;
    printf("Enter the position ");
    scanf("%d", &loc);
    printf("Enter the value to be inserted ");
    scanf("%d", &data);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    for (i = 0; i < loc; i++)
    {
        if (temp->next == NULL)
        {
            return;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    prev->next = newnode;
    newnode->next = temp;
}
void search()
{
    struct node *newnode;
    int item, i = 0, flag = 0;
    newnode = head;
    if (newnode == NULL)
    {
        printf("\nList Is Empty\n");
    }
    else
    {
        printf("\nEnter Value That Want To Search ?\n");
        scanf("%d", &item);
        while (newnode != NULL)
        {
            if (newnode->data == item)
            {
                printf("Value Found At Location %d\n", i + 1);
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            i++;
            newnode = newnode->next;
        }
        if (flag == 0)
        {
            printf("Value not Found");
        }
    }
}
void deleteValue()
{
    struct node *newnode, *newnode1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to Delete: \n");
    scanf("%d", &loc);
    newnode = head;
    for (i = 0; i < loc; i++)
    {
        newnode1 = newnode;
        newnode = newnode->next;

        if (newnode == NULL)
        {
            printf("\nERROR");
            return;
        }
    }
    newnode1->next = newnode->next;
    free(newnode);
    printf("\nDeleted node %d ", loc + 1);
}
void displayList()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("Data Is Empty");
    }
    else
    {
        printf("\nValues : ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert At Front\t2.Insert At End \t3.Insert By Position \t4.Search \t5.Delete\t6.Display\t7.Exit\n");
        printf("Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertatfront();
            break;
        case 2:
            insertatEnd();
            break;
        case 3:
            insertbyPosition();
            break;
        case 4:
            search();
            break;
        case 5:
            deleteValue();
            break;
        case 6:
            displayList();
            break;
        case 7:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}
