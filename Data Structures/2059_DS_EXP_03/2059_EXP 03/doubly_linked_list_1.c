//doubly linked list operations considering one external reference pointer start
//Name: Umesh Pandit Hakke
//Roll No: 2059
//SY CSE 
//Div: A Batch:S4
#include <stdlib.h>
#include<stdio.h>
struct node {
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL,*p,*q;
int main(){
	int a;
	printf("Code for dobully linked list with single external referance pointer");
	printf("\n1.Create at start \n2.Create at end \n3.Create at given location \n4.Delete at start \n5.Delete at end \n6.Delete at given location \n7.Traverse \n8.Exit.");
		do {
	printf("\nchoose one of the from above: ");
	scanf("%d",&a);
	switch (a){
		case 1:
			create_at_start();
			break;
		case 2:
			create_at_end();
			break;
		case 3:
			create_at_givenlocation();
			break;
		case 4:
			delete_at_start();
			break;
		case 5:
			delete_at_end();
			break;
		case 6:
			delete_at_givenlocation();
			break;
		case 7:
			traverse();
			break;
		case 8:
			printf("exit");
			break;
		default :
			printf("enter valid input in range of 1-7\n");
			break;
	}
}while(a!=8);
}
void create_at_start(){
	p=(NODE*)malloc(sizeof (NODE));
	printf("enter the data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		start=p;
		p->next=NULL;
		p->prev=NULL;
	}
	else{
		start->prev=p;
		p->next=start;
		start=p;
		p->prev=NULL;
		
	}
}
void traverse(){
	if (start==NULL){
		printf("Linked lsit is empty\n");
	}
	else {
		q=start;
		while(q!=NULL){
			printf("%d\t",q->data);
			q=q->next;
		}
	}
}
void create_at_end(){
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		start=p;
		p->next=NULL;
		p->prev=NULL;
	}
	else{
		q=start;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
		p->prev=q;
		p->next=NULL;
	}
}
void create_at_givenlocation(){
	int loc,i=1;
	printf("enter the location");
	scanf("%d",&loc);
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		if (loc==1){
			start=p;
			p->next=NULL;
			p->prev=NULL;
		}
		else {
			printf("Invalid lovation");
			free(p);
		}
	}
	else {
		if (loc==1){
			start->prev=p;
			p->next=start;
			start=p;
			p->prev=NULL;
		}
		else {
			q=start;
			while(i<loc-1&&q!=NULL){
				q=q->next;
			}
			if (q!=NULL){
				if (q->next==NULL){
					q->next=p;
					p->prev=q;
					p->next=NULL;
				}
				else{
					q->next->prev=p;
					p->next=q->next;
					q->next=p;
					p->prev=q;	
				}
			}
			else{
				printf("Invalid location");
			}
		}
	}
}
void delete_at_start(){
	if (start==NULL){
		printf("linked list is empty");
	}
	else if(start->next==NULL) {
		p=start;
		printf("Deleting %d",p->data);
		free(p);
		start=NULL;
	}
	else{
		p=start;
		start=p->next;
		start->prev=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
}
void delete_at_end(){
	if (start==NULL){
		printf("linked list is empty\n");
	}
	else if(start->next==NULL){
		p=start;
		start=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
	else{
		p=start;
		while(p->next!=NULL){
			q=p;
			p=p->next;
		}
		q->next=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
}
void delete_at_givenlocation(){
	int loc,i=1;
	printf("enter the location\n");
	scanf("%d",&loc);
	if (start==NULL){
		printf("linked list is empty");
	}
	else if(start->next==NULL){
		if (loc==1){
			p=start;
			start=NULL;
			printf("deleting %d",p->data);
			free(p);
		}
		else{
			printf("invalid location");
		}
	}
	else{
		if (loc==1){
			p=start;
			p->next->prev=NULL;
			start=p->next;
			printf("deleting %d",p->data);
			free(p);
		}
		else{
			p=start;
			while(i<loc&&p!=NULL){
				q=p;
				p=p->next;
				i++;
			}
			if(p!=NULL){
				if (p->next==NULL){
					q->next=NULL;
					printf("deleting %d",p->data);
					free(p);
				}
				else{
					p->next->prev=q;
					q->next=p->next;
					printf("deleting %d",p->data);
					free(p);
				}
			}
		}
	}
}
