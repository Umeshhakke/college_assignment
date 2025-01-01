/*
Name : Umesh Pandit Hakke
Roll No: 2059
Queue Using Linked List.
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
		printf("1.Enqueue \n2.Dequeue \n3.Top of Queue \n4.Traverse \n5.Exit\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				Enqueue();
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Top_of_Queue();
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

void Enqueue()
{
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data to enqueud: ");
	scanf("%d",&p->data);
	
	if (start==NULL)
	{
		start=p;
		p->next=NULL;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->next=NULL;
	}
}

void Dequeue()
{
	if (start==NULL)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		if (start->next==NULL)
		{
			p=start;
			start=NULL;
			printf("%d is dequeued\n",p->data);
			free(p);
		}
		else 
		{
			p=start;
			start=p->next;
			printf("%d is dequeued\n",p->data);
			free(p);
		}
	}
}

void traverse()
{
	if (start==NULL)
	{
		printf("there no exists queue\n");
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
void Top_of_Queue()
{
	if (start==NULL)
	return;
	printf("\n%d\n",start->data);
}
