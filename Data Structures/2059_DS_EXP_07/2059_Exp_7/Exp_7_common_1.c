/*
Implement stack using array
Name: Umesh Hakke
Roll No: 2059
S.Y (A)
Batch S4
*/
#include <stdio.h>
#include <stdlib.h>
void push(int stack[],int size,int *top);
void pop(int stack[],int size,int *top);
int main ()
{
	int size,top=-1,choice;
	printf("Enter the size of stack you want too..: ");
	scanf("%d",&size);
	int stack[size];
	do
	{
		printf("Choose From below: \n1.Push \n2.pop \n3.exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Push: ");
				push(stack,size,&top);
				break;
			case 2:
				printf("Pop: ");
				pop(stack,size,&top);
				break;
			case 3:
				printf("Exit...");
		}		
	}while(choice!=3);
}

void push(int stack[],int size,int *top)
{
	if (*top<size-1)
	{
		(*top)++;
		printf("Enter the data to push: ");
		scanf("%d",&stack[*top]);
	}
	else 
	{
		printf("Stack Overflow\n");
	}
}

void pop(int stack[],int size,int *top)
{
	if (*top>=0)
	{
		printf(" poped : %d ",stack[*top]);
		(*top)--;
	}
	else
	{
		printf("Stack Underflow");
	}
}
