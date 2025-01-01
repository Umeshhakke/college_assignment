//Check if given linked list is a palindrome
//Name: Umesh Pandit Hakke
//Class: S.Y
//Div: A
//Batch : S4
#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node NODE;
NODE *start = NULL, *start1 = NULL,*end=NULL, *p, *q, *p1, *r;

void Create_at_start();
void Create_at_end();
void Create_at_given_location();
void Delete_at_start();
void Delete_at_end();
void Delete_at_given_location();
void Traverse();
void Traverse1();
void reverse();
void exitl();
int cont=0;
int main() {
	int choice;
	printf("Program of Linked List\n");
	printf("Choose a number from the options below:\n");
	printf("1) Create at start\n2) Create at end\n3) Create at given location\n4)Delete at start\n5) Delete at end\n6)Delete at given location \n7)Traverse\n8) Free Memory\n9) Check\n10) Traverse1\n11)exit\n");
	
	do {
		printf("Choose an option: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				Create_at_start();
				break;
			case 2:
				Create_at_end();
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
				exitl();
				exita();
				break;
			case 9:
				reverse();
				check();
				break;
			case 10:
				Traverse1();
				break;
			case 11:
				printf("Exit :)\n"); 
				break;
			default:
				printf("Invalid option! Please try again.\n");
		}
	} while (choice != 11);

	return 0;
}

void Create_at_start() {
	printf("Enter data: ");
	p = (NODE*)malloc(sizeof(NODE));
	scanf("%d", &p->data);
	if (start == NULL) {
		p->next = NULL;
		start = p;
	} else {
		p->next = start;
		start = p;
	}
}

void Traverse() {
	printf("Linked List consists of: \n");
	cont=0;
	if (start == NULL) {
		printf("Linked List is empty\n");
	} else {
		q = start;
		while (q != NULL) {
			printf("%d\t", q->data);
			q = q->next;
			cont++;
		}
		printf("\n%d",cont);
	}
}

void Traverse1() {
	printf("Linked List 1 consists of: \n");
	if (start1 == NULL) {
		printf("Linked List 1 is empty\n");
	} else {
		q = start1;
		while (q != NULL) {
			printf("%d\t", q->data);
			q = q->next;
		}
		printf("\n");
	}
}

void Create_at_end() {
	printf("Enter data: ");
	p = (NODE*)malloc(sizeof(NODE));
	scanf("%d", &p->data);
	if (start == NULL) {
		p->next = NULL;
		start = p;
	} else {
		q = start;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
		p->next = NULL;
	}
}

void Delete_at_start() {
	printf("Deleting the first node\n");
	if (start == NULL) {
		printf("Linked List is empty\n");
	} else {
		p = start;
		start = p->next;
		printf("Deleting %d\n", p->data);
		free(p);
	}
}

void Delete_at_end() {
	printf("Deleting the last node\n");
	if (start == NULL) {
		printf("Linked List is empty\n");
	} else if (start->next == NULL) {
		printf("Deleting %d\n", start->data);
		free(start);
		start = NULL;
	} else {
		p = start;
		while (p->next != NULL) {
			q = p;
			p = p->next;
		}
		q->next = NULL;
		printf("Deleting %d\n", p->data);
		free(p);
	}
}

void exitl() {
	if (start1 == NULL) return;
	q = start1;
	while (q->next != NULL) {
		p = q;
		q = q->next;
		printf("Deleting %d\n", p->data);
		free(p);
	}
	printf("Deleting %d\n", q->data);
	free(q);
	start1 = NULL;
}

void exita() {
	if (start == NULL) return;
	q = start;
	while (q->next != NULL) {
		p = q;
		q = q->next;
		printf("Deleting %d\n", p->data);
		free(p);
	}
	printf("Deleting %d\n", q->data);
	free(q);
	start = NULL;
}

void reverse() {
	if (cont%2!=0){
		q=start;
		int c=0;
		while (c!=cont/2&&q!=NULL){
			r=q;
			q=q->next;
			c++;
		}
		r->next=NULL;
		end=q;
		while (end != NULL) {
			p = end;
			end = end->next;
			
			p1 = (NODE*)malloc(sizeof(NODE));
			p1->data = p->data;
			p1->next = start1;
			start1 = p1;
			free(p);
		}
	}
	if (cont%2==0){
		q=start;
		int c=0;
		while (c!=cont/2&&q!=NULL){
			r=q;
			q=q->next;
			c++;
		}
		r->next=NULL;
		end=q;
		while (end != NULL) {
			p = end;
			end = end->next;
			
			p1 = (NODE*)malloc(sizeof(NODE));
			p1->data = p->data;
			p1->next = start1;
			start1 = p1;
			free(p);
		}
	}
}
void check(){
	if (cont%2==0){
		q=start;
		r=start1;
		while (q!=NULL && r!=NULL){
			if (q->data==r->data)
			printf("");
			else goto end;
			q=q->next;
			r=r->next;
		}
		printf("\nlinked list is a palindrome\n");
		goto end1;
	}
	if (cont%2!=0){
		q=start;
		r=start1;
		while (q!=NULL && r->next!=NULL){
			if (q->data==r->data)
			printf("");
			else goto end;
			q=q->next;
			r=r->next;
		}
		printf("\nLinked list is a palindrome\n");
		goto end1;
	}
	end:
		printf("\nlinked list is not a palindrome\n");
	end1:
		printf("");
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

