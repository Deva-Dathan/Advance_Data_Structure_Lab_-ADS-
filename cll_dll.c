#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node* next;
struct Node* prev;
};

struct Node* head;

void insertAtBegining(int x)
{
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = x;
temp->next = head;
temp->prev = NULL;
if(head != NULL)
head->prev = temp;
head = temp;
}

void insertAtEnd(int x)
{
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = x;
temp->next = NULL;
struct Node* temp2 = head;
while(temp2->next != NULL)
{
temp2 = temp2->next;
}
temp2->next = temp;
temp->prev = temp2;
}

void printList()
{
struct Node* temp = head;
printf("List is: ");
while(temp != NULL)
{
printf("%d ",temp->data);
temp = temp->next;
}
printf("\n");
}

int main()
{
head = NULL;
int n,i,x;
printf("Enter the number of elements in the list: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the element: ");
scanf("%d",&x);
insertAtEnd(x);
}
printList();
return 0;
}