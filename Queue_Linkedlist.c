#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front,*rear;

void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter The Value:");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front->next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty Queue\n");  
    }  
    else  
    {   printf("\nValues Are:");  
        while(ptr != NULL)   
        {  
            printf("\t%d",ptr -> data);  
            ptr=ptr->next;  
        }  
        printf("\n");
    }  
} 

void main()  
{  
    int choice;   
    while(choice != 4)   
    { 
        printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");  
        printf("\nEnter Your Choice:");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:enqueue();  
            break;  
            case 2:dequeue();  
            break;  
            case 3:display();  
            break;  
            case 4:exit(0);  
            break;  
            default:printf("\nInvalid Choice.....Enter a Valid Choice\n");  
        }  
    }  
}  