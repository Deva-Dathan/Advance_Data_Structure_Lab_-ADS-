#include<stdio.h>
#include<stdlib.h>
int stack[5];
int top=-1;
void push_arr(){
int num;
if(top==5)
{
	printf("Array overflow..");
	return;
}
else{
	printf("Enter the Value:");
	scanf("%d",&num);
	top=top+1;
	stack[top]=num;
}
}

void pop_arr()
{
	
   if(top==-1)
   {
		printf("Underflow");
		return;
	}	
   else
   {
   		printf("Deleted item %d\n",stack[top]);
   }		top=top-1;
}
void display_item()
{
	int i;
 printf("\nValues Are:\t");
 for(i=top;i>=0;i--)
 {
 	printf("%d \t",stack[i]);
 }
 if(top==-1)
 {
 	printf("STACK IS EMPTY");
 }

}
int main()
{
    while(1)
    {
    	int ch;
        printf("\n1.Push \t 2.POP \t 3.DISPLAY\n");
        printf("\nEnter The Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push_arr();
            break;
            case 2: pop_arr();
            break;
            case 3: display_item();
            break;
            case 4:exit(0);
            default: printf("Invalid Choice");
            
        }
	}
	return 0;
}
