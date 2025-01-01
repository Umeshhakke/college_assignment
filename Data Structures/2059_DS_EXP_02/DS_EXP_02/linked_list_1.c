//program of linked list (single external referance)
//Name:Umesh Pandit Hakke 
//Roll no:- 2059
//Batch S4
//SY Div A
#include <stdlib.h>
#include <stdio.h>
void Create_at_start();
void Traverse();
void Creat_at_end();
void Create_at_given_location();
void Delete_at_start();
void Delete_at_end();
void Delete_at_given_location();
struct node {
	int data ;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL,*p,*q;
int main()
{
	int a;
	printf("Program of Linked List");
	printf("Choose Number from below");
	printf("1) Create at start \n2) Create at end \n3) Create at given location \n4) Delete at start \n5) Delete at end \n6) Delete at given location \n7) Traverse \n8) Exit \n");
	do{
			printf("Choose Number");
			scanf("%d",&a);
	switch (a){
		case 1:
			 Create_at_start();
			 break;
		case 2:
			Creat_at_end();
			break;
		case 3:
			Create_at_given_location();
			break;
		case 4:
			Delete_at_start();
			break;
		case 5:
			 Delete_at_end();
			 break;
		case 6:
			 Delete_at_given_location();
			 break;
		case 7:
			Traverse();
			break;	
		case 8:
			printf("Exit :)"); 
	}
	}while(a!=8);

}
void Create_at_start(){
			printf("enter data\n");
			p=(NODE*)malloc(sizeof(NODE));
			scanf("%d",&p->data);
			if (start==NULL){
				p->next=NULL;
				start=p;
			}
			else {
				p->next=start;
				start=p;
			}
}
void Traverse(){
	printf("Linked List consist of: \n");
	if(start==NULL){
		printf("Linked List is empty \n");
	}
	else {
		q=start;
		while(q!=NULL){
			printf("%d\t",q->data);
			q=q->next;
		
		}
	}
}
void Creat_at_end(){
	printf("enter data\n");
	p=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&p->data);
	if (start==NULL){
		p->next=NULL;
		start=p;
	}
	else{
		if (start->next==NULL){
			start->next=p;
			p->next=NULL;
		}
		else {
			q=start;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
			p->next=NULL;
		}
	}
}
void Create_at_given_location(){
	int loc;
	printf("enter location\n");
	scanf("%d",&loc);
	printf("Enter data \n");
	p=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&p->data);
	if (start==NULL){
		if (loc==1){
			p->next=NULL;
			start=p;
		}
		else {
			printf("Invalid Location");
			free(p);
		}
	}
	else {
		if (loc==1){
			p->next=start;
			start=p;
		}
		else {
			q=start;
			int i=1;
			while (i<loc-1){
				q=q->next;
				i++;
			}
			if (q!=NULL){
				p->next=q->next;
				q->next=p;
			}
			else {
				printf("Invalid Location");
				free(p);
			}
		}
	}
}
void Delete_at_start(){
	printf("you have called delete at start\n");
	if (start==NULL){
		printf("Linked List is Empty");
	}

	else if (start->next==NULL){
		p=start;
		start=NULL;
		printf("deleting %d",p->data);
		free(p);
	}
	else {
		p=start;
		start=p->next;
		printf("deleting %d",p->data);
		free(p);
	}
}
void Delete_at_end(){
	printf("you are going to delete last node\n");
	if (start==NULL){
		printf("Linked List is Empty\n");
	}

	else if (start->next==NULL){
			p->next=NULL;
			p=start;
			printf("you have delated %d\n",p->data);
			free(p);
		}
		else {
			p=start;
			while (p->next!=NULL){
				q=p;
				p=p->next;
			}
			q->next=NULL;
			printf("you are deleting %d\n",p->data);
			free(p);
		}
}
void Delete_at_given_location(){
	int loc;
	printf("performing delete at given location\n");
	printf("enter a location");
	scanf("%d",&loc);
	if (start==NULL){
		printf("Linked List is Empty\n");
	}
	else {
		if (loc==1){
			p=start;
			printf("you are deleting %d\n",p->data);
			start=NULL;
			free(p);
		}
		else {
			int i=1;
			p=start;
			while(i<loc && p!=NULL){
				q=p;
				p=p->next;
				i++;
			}
			if (p!=NULL){
				q->next=p->next;
				printf("deleting %d\n",p->data);
				free(p);
			}
			else {
				printf("Invalid Location\n");
			}
		}
}
	}

