+/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space
*/
/*
Name: Umesh Pandit Hakke
Class: S.Y
Div: A
Roll No: 2059
*/
#include <stdlib.h>
#include<stdio.h>

struct node 
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node NODE; 
//Declaration of functions
void create_at_start(NODE **start);
void create_at_end(NODE **start);
void create_at_givenlocation();
void delete_at_start(NODE **start);
void delete_at_end(NODE **start);
void delete_at_givenlocation(NODE **start);
void check_for_pair(NODE **start);
void traverse(NODE **start);
void exit_list(NODE **start); 

int main()
{
	NODE *start=NULL,*p,*q;
	int a;
	printf("Code for dobully linked list with single external referance pointer");
	printf("\n1.Create at start \n2.Create at end \n3.Create at given location \n4.Delete at start \n5.Delete at end \n6.Delete at given location \n7.Traverse \n8.Get for sum pair\n9.Exit");
		do {
	printf("\nchoose one of the from above: ");
	scanf("%d",&a);
	switch (a){								
		case 1:
			create_at_start(&start);
			break;
		case 2:
			create_at_end(&start);
			break;
		case 3:
			create_at_givenlocation(&start);
			break;
		case 4:
			delete_at_start(&start);
			break;
		case 5:
			delete_at_end(&start);
			break;
		case 6:
			delete_at_givenlocation(&start);
			break;
		case 7:
			traverse( &start);
			break;
		case 8:
			check_for_pair(&start);
			break;
		case 9:
			printf("exit");
			exit_list(&start);
			break;
		default :
			printf("enter valid input in range of 1-7\n");
			break;
	}
}while(a!=9);
}

void create_at_start(NODE **start)			//function to create the node at start
{
	NODE* p;
	p=(NODE*)malloc(sizeof (NODE));			//Allocating a memory location to store the data input by user
	printf("enter the data\n");
	scanf("%d",&p->data);
	if (*start==NULL)					//if the linked list is empty then this is the first node we create here 
	{
		*start=p;
		p->next=NULL;
		p->prev=NULL;
	}
	else							
	{						
		(*start)->prev=p;
		p->next=*start;
		*start=p;						//Node is added to the beginning of linked list
		p->prev=NULL;
		
	}
}

void traverse(NODE **start)				//Function to print the elements of linked list
{
	if (*start==NULL)					//condition to check the the linked list is empty or not
	{
		printf("Linked lsit is empty\n");
	}
	else 							
	{
		NODE* q=*start;
		while(q!=NULL)					//printing the nodes till pointer points to the node it exit when it point to NULL
		{
			printf("%d\t",q->data);
			q=q->next;
		}
	}
}

void create_at_end(NODE **start)		//Function to create node at End
{
	NODE* p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data\n");
	scanf("%d",&p->data);
	if (*start==NULL)
	{
		*start=p;
		p->next=NULL;
		p->prev=NULL;
	}
	else
	{
		NODE* q=*start;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
		p->prev=q;
		p->next=NULL;
	}
}

void create_at_givenlocation(NODE **start)			//Function to add NODE at given location (Valid)
{
	int loc,i=1;
	NODE* p;
	NODE* q;
	printf("enter the location");
	scanf("%d",&loc);
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter data\n");
	scanf("%d",&p->data);
	if (*start==NULL)
	{
		if (loc==1)
		{
			*start=p;
			p->next=NULL;
			p->prev=NULL;
		}
		else 
		{
			printf("Invalid lovation");
			free(p);
		}
	}
	else 
	{
		if (loc==1)
		{
			(*start)->prev=p;
			p->next=*start;
			*start=p;
			p->prev=NULL;
		}
		else 
		{
			q=*start;
			while(i<loc-1&&q!=NULL)
			{
				q=q->next;
			}
			if (q!=NULL)
			{
				if (q->next==NULL)
				{
					q->next=p;
					p->prev=q;
					p->next=NULL;
				}
				else
				{
					q->next->prev=p;
					p->next=q->next;
					q->next=p;
					p->prev=q;	
				}
			}
			else
			{
				printf("Invalid location");
			}
		}
	}
}

void delete_at_start(NODE **start)				//Function to delete the NDODE which is pointed by start
{
	NODE* p;
	if (start==NULL)
	{
		printf("linked list is empty");
	}
	else if((*start)->next==NULL) 
	{
		p=*start;
		printf("Deleting %d",p->data);
		free(p);
		*start=NULL;
	}
	else
	{
		 p=*start;
		*start=p->next;
		(*start)->prev=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
}
void delete_at_end(NODE **start)				//Function to delete the NODE which is last NODE of linked list
{
	NODE* p;
	NODE* q;
	if (*start==NULL)
	{
		printf("linked list is empty\n");
	}
	else if((*start)->next==NULL)
	{
		p=*start;
		*start=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
	else
	{
		
		 p=*start;
		while(p->next!=NULL)
		{
		 q=p;
			p=p->next;
		}
		q->next=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
}

void delete_at_givenlocation(NODE **start)			//Function to delete the NODE from the given location
{
	NODE* p;
	NODE* q;
	int loc,i=1;
	printf("enter the location\n");
	scanf("%d",&loc);
	if (*start==NULL)
	{
		printf("linked list is empty");
	}
	else if((*start)->next==NULL){
		if (loc==1)
		{
			p=*start;
			*start=NULL;
			printf("deleting %d",p->data);
			free(p);
		}
		else
		{
			printf("invalid location");
		}
	}
	else
	{
		if (loc==1){
			p=*start;
			p->next->prev=NULL;
			*start=p->next;
			printf("deleting %d",p->data);
			free(p);
		}
		else{
			p=*start;
			while(i<loc&&p!=NULL)
			{
				q=p;
				p=p->next;
				i++;
			}
			if(p!=NULL)
			{
				if (p->next==NULL)
				{
					q->next=NULL;
					printf("deleting %d",p->data);
					free(p);
				}
				else
				{
					p->next->prev=q;
					q->next=p->next;
					printf("deleting %d",p->data);
					free(p);
				}
			}
		}
	}
}

void exit_list(NODE **start) 			//Function Deallocate the Allocated memory locations to avoid the memory leak
{
	NODE* p;
	NODE* q;
    if (*start == NULL) 
	{
        return;
    }
    
    q = *start;
    while (q->next != NULL) 
	{
        p = q;
        q = q->next;
        q->prev=NULL;
        printf("Deleting %d\n", p->data);
        free(p);
    }
    printf("Deleting %d\n", q->data);
    free(q);
    *start = NULL;
}

void check_for_pair(NODE **start) 					//Function to check the pair in linked list whose sum matches to user requirement
{
    NODE* q;
    NODE* temp;
    int x, var1, var2;

    printf("Enter the number to find the sum of ordered pair: ");
    scanf("%d", &x);

    q = *start;
    while (q != NULL) 
	{
        var1 = q->data;
        temp = q->next; 							 // Start checking pairs from the next node
        while (temp != NULL)
		 {
            var2 = temp->data;  
            if (x == var1 + var2)
			 {
                printf("(%d, %d)\n", var1, var2);    // Print the pair which gives the output asked by the user
            }
            temp = temp->next;  					 // Move to the next node 
        }
        q = q->next; 								 // shift the outer pointer to the next node
    }
}

/*
Input : start : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
*/
