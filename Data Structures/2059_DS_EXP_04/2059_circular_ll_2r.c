/*
Write program to implement circular linked list operations using two external reference pointers start and last. 
Name: Umesh Pandit Hakke
Class: S.Y (A)
Batch:S4
Roll No: 2059
*/
#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL,*last=NULL,*p,*q;
int main(){
	int a;
	printf("Circular linked list \n");
	printf("enter the number from listed below\n");
	do{
	printf("1.create at start\n2.create at end\n3.create at given location\n4.delete at start\n5.delete at end\n6.delete at given location\n7.traverse\n");
	scanf("%d",&a);
	switch (a){
		case 1:
			create_at_start();
			break;
		case 2: 
			create_at_end();
			break;
		case 3:
			create_at_given_location();
			break;
		case 4:
			delete_at_start();
			break;
		case 5: 
			delete_at_end();
			break;
		case 6:
			delete_at_given_location();
			break;
		case 7:
			traverse();
			break;
		case 8:
			printf("You have sucessfully exited the program\n");
			exit_list();
			break;
	}
	}while (a!=8);
}
void create_at_start(){
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		start=p;
		p->next=p;
		last=p;
	}
	else {
		p->next=start;
		start=p;
		last->next=start;
	}
}
void traverse(){
	if (start==NULL){
		printf("linked list is empty\n");
	}
	else{
		q=start;
		do{
			printf("%d\t",q->data);
			q=q->next;
		}while (q!=start);
	}
	printf("\n");
}
void exit_list() {
    if (start == NULL) {
        return;
    }
    
    q = start;
    while (q->next != start) {
        p = q;
        q = q->next;
        printf("Deleting %d\n", p->data);
        free(p);
    }
    printf("Deleting %d\n", q->data);
    free(q);
    start = NULL;
    last = NULL;
}
void create_at_end(){
	p=(NODE*)malloc(sizeof(NODE));
	printf("enter data\n");
	scanf("%d",&p->data);
	if (start==NULL){
		start=p;
		p->next=p;
		last=p;
	}
	else {
		p->next=start;
		last->next=p;
		last=p;
	}
}
void create_at_given_location(){
	p=(NODE*)malloc(sizeof(NODE));
	int loc,i=1;
	printf("enter the data\n");
	scanf("%d",&p->data);
	printf("enter the location\n");
	scanf("%d",&loc);
	if(start==NULL){
		if (loc==1){
			p->next=p;
			start=p;
			last=p;
		}
		else {
			printf("invalid location\n"); 
			free(p);
		}
	}
	else if(start->next==start){
		if (loc==1){
			p->next=start;
			last->next=p;
			start=p;	
		}
		else {
			printf("invalid location\n");
			free(p);
		}
	}
	else {
		q=start;
		while(i<loc-1 && q->next!=start){
			q=q->next;
			i++;
		}
		if (q->next!=start){
		p->next=q->next;
		q->next=p;
	}
	else if (q->next==start){
		q->next=p;
		p->next=start;
		last=p;
	}
	else {
		printf("invalid location\n");
	}
	}
}
void delete_at_start(){
	if (start==NULL){
		printf("linked list is empty\n");
	}
	else if (start->next==start)
	{
		start=p;
		printf("%d is deleted",p->data);
		free(p);
		start=NULL;
		last=NULL;
	}
	else{
		p=start;
		start=p->next;
		printf("deleting %d\n",p->data);
		free(p);
		last->next=start;
	}
}
void delete_at_end(){
	if (start==NULL){
		printf("linked lsit is empty\n");
	}
	else if (start->next==start){
		p=start;
		printf("deleting %d \n",p->data);
		free(p);
		start=NULL;
		last=NULL;
	}
	else{
		p=start;
		while(p!=last){
			q=p;
			p=p->next;
		}
	q->next=start;
	printf("deleting %d\n",p->data);
	free(p);
		
	}
}
void delete_at_given_location(){
	int i=1,loc;
	printf("enter location");
	scanf("%d",&loc);
	if (start==NULL){
		printf("linked list is empty\n");
	}
	else if(start->next==start){
		if (loc==1){
			p=start;
			start=NULL;
			last=NULL;
			printf("deleting %d\n",p->data);
			free(p);
		}
		else {
			printf("invalid input ");
		}
	}
	else {
		p=start;
		while(i<loc&&p->next!=start){
			q=p;
			p=p->next;
		}
		if (p->next!=NULL){
		q->next=p->next;
		printf("deleting %d\n",p->data);
		free(p);
	}
	else if(p->next==NULL){
		q->next=start;
		printf("%d is deleted\n",p->data);
		free(p);
		last=q;
	}
	else {
		printf("invalid location");
	}
	}
}
