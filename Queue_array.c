#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 10  
int front = -1, rear = -1;  
int queue[maxsize];  
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
            default:printf("\nInvalid Choice.....");  
        }  
    }  
}    
void enqueue()  
{  
    int item;  
    printf("\nEnter the Values:");  
    scanf("3%d",&item);      
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;
}  
void dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;          
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        } 
    }      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nQueue Is Empty\n");  
    }  
    else  
    {   printf("\nValues Are: ");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\t%d",queue[i]);  
        }
        printf("\n");    
    }  
}  