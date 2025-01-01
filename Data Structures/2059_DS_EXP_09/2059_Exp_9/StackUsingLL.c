/*
Name : Umesh Pandit Hakke
Roll No: 2059
Stack Using Linked List.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL,*p,*q;

int main()
{
	int a;
	printf("program for queue using linked list");
	do
	{
		printf("\nFollowing operations you can perform: \n");
		printf("1.Push\n2.Pop \n3.Top of stack \n4.Traverse \n5.Exit\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				Push();
				break;
			case 2:
				Pop();
				break;
			case 3:
				Top_of_stack();
				break;
			case 4:
				traverse();
				break;
			case 5:
				printf("Exiting>>>...");
				break;
			default: 
				printf("invalid input\n");
				break;
		}
	}while(a!=5);
}

void Push()
{
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data to Push: ");
	scanf("%d",&p->data);
	
	if (start==NULL)
	{
		start=p;
		p->next=NULL;
	}
	else
	{
		p->next=start;
		start=p;
	}
}

void Pop()
{
	if (start==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		if (start->next==NULL)
		{
			p=start;
			start=NULL;
			printf("%d is Poped\n",p->data);
			free(p);
		}
		else 
		{
			p=start;
			start=p->next;
			printf("%d is Poped\n",p->data);
			free(p);
		}
	}
}

void traverse()
{
	if (start==NULL)
	{
		printf("there no exists Stack\n");
	}
	else 
	{
		q=start;
		while(q!=NULL)
		{
			printf("%d\t",q->data);
			q=q->next;
		}
	}
}
void Top_of_stack()
{
	if (start==NULL)
	return;
	printf("\n%d\n",start->data);
}
