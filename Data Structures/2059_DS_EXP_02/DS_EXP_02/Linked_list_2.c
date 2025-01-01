//Program of Linked list with two external referance pointer.
//Name:Umesh Pandit Hakke 
//Roll no:- 2059
//Batch S4
//SY Div A
#include <stdlib.h>
#include<conio.h>
void Create_at_start();
void Create_at_end();
void Create_at_givenlocation();
void Delete_at_start();
void Delete_at_end();
void Delete_at_givenlocation();
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL,*last=NULL,*p,*q;
int main(){
	int a;
	printf("Program of Singuly linked list with two external referance pointer\n");
	do{
	printf("\n1) Create at start \n2) Create at end \n3) Create at given location \n4)Delete at start \n5) Delete at end \n6) Delete at given location \n7) Traverse \n");
	printf("enter the number from above list\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			Create_at_start();
			break;
		case 2:
			Create_at_end();
			break;
		case 3:
			Create_at_givenlocation();
			break;
		case 4:
			Delete_at_start();
			break;
		case 5:
			Delete_at_end();
			break;
		case 6:
			Delete_at_givenlocation();
			break;
		case 7:
			Traverse();
			break;
		case 8:
		printf("exit");
		break;
	}
}while(a!=8);
}
void Create_at_start(){
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		p->next=NULL;
		start=p;
		last=p;
	}
	else{
		p->next=start;
		start=p;
	}
}
void Traverse(){
	if (start==NULL){
		printf("linked list is empty\n");
	}	
	else{
		q=start;
		while(q!=NULL){
			printf("%d\t",q->data);
			q=q->next;
		}
	}
}
void Create_at_end(){
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter the data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		start=p;
		p->next=NULL;
		last=NULL;
	}
	else if (start->next==NULL){
		start->next=p;
		p->next=NULL;
		last=p;
	}
	else{
		q=start;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
		last=p;
	}
}
void Create_at_givenlocation(){
	int loc;
	printf("enter Location to edit at given location");
	scanf("%d",&loc);
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Number\n");
	scanf("%d",&p->data);
	if (start==NULL){
		if (loc==1){
			start=p;
			p->next=NULL;
			last=p;	
		}
		else {
			printf("linked list is empty\nEntered location is invalid\n");
			free(p);
		}
	}
	else {
		if (start->next==NULL){
			if (loc==1){
				p->next=start;
				start=p;
			}
			else{
				printf("Linked list is containing only one element");
				free(p);
			}
		}
		else{
			q=start;
			int i=1;
			while(i<loc-1&&q!=NULL){
				q=q->next;
			}
			if (q!=NULL){
				p->next=q->next;
				q->next=p;
			}
			else{
				printf("Invalid location");
				free(p);
			}
		}
		}
	}
void Delete_at_start(){
	if (start==NULL){
		printf("Linked list is Empty");
	}
	else if(start->next==NULL){
		p=start;
		printf("Deleting %d",p->data);
		free(p);
		last=NULL;
		start=NULL;
			}
	else{
		p=start;
		start=p->next;
		printf("Deleting %d",p->data);
		free(p);
	}
}
void Delete_at_end(){
	if (start==NULL){
		printf("Linked list is Empty\n");
	}
	else if(start->next==NULL){
		p=start;
		printf("Deleting %d",p->data);
		start=NULL;
		last=NULL;
		free(p);
	}
	else{
		p=start;
		while(p->next!=NULL){
			q=p;
			p=p->next;
		}
		q->next=NULL;
		printf("Deleting %d",p->data);
		free(p);
		last=q;
	}
}
void Delete_at_givenlocation(){
	int loc,i=1;
	printf("enter the location to remove data from given location\n");
	scanf("%d",&loc);
	if(start==NULL){
		printf("Linked List is empty\n");
	}
	else if(start->next==NULL){
		if (loc==1){
			p=start;
			printf("deleting %d",p->data);
			free(p);
			start=NULL;
			last=NULL;
		}
		else{
			printf("Linked list contain only one element");
		}
	}
	else{
		p=start;
		while(i<loc&&p!=NULL){
			q=p;
			p=p->next;
		}
		if (p!=NULL){
			if (p->next==NULL){
			q->next=NULL;
			last=q;				
			}
			q->next=p->next;
			printf("Deleting %d",p->data);
			free(p);
		}
	}
}
