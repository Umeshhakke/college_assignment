/*
Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1


Name: Umesh Pandit Hakke
Class: S.Y (A)
Batch: S4
*/
#include <stdio.h>
#include <stdlib.h>
void push(int array[], int* top, int size);
void traverse(int array[],int* top,int size);
void nerest_largest_element(int array[],int* top,int size);
int main(){
	int choice,size;
	int array[size];
	int top=-1;
	printf("Enter the size of stack: \n");
	scanf("%d",&size);
	printf("You can operate three operation stack shown below: \n");
	do {
		printf("\nchoose One : \n");
		printf("1.Push\n2.Pop\n3.Traverse\n4.nerest_largest_element\n5.exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				push(array,&top,size);
				break;
			case 2:
				pop(array,&top,size);
				break;
			case 3:
				traverse(array,&top,size);
				break;
			case 4:
				nerest_largest_element(array,&top,size);
				break;
			case 5:
				printf("exiting _-_-_-_>>\n");
				break;
			default:
				printf("Invslid location");
		}
	}while (choice != 5);
}

void push(int array[], int* top, int size) 
{
    if (*top < size - 1) { 
        (*top)++;
        printf("Enter the data you want to push to the stack: \n");
        scanf("%d", &array[*top]);
        printf("%d is pushed\n", array[*top]);
    } else {
        printf("Stack is overflow\n");
    }
}

void pop(int array[],int* top,int size)
{
	if (*top==-1){
		printf("Stack Underflow\n");
	}
	else{
		printf("%d is poped",array[*top]);
		(*top)--;
	}
}

void traverse(int array[],int* top,int size)
{
	int val=*top;
	if (val == -1){
		printf("Stack is empty\n");
	}
	else{
		while(val!=-1){
			printf("%d\t",array[val]);
			val--;
		}
	}
}

void nerest_largest_element(int array[],int* top,int size)
{
	int i,j;
	printf("Checking for nearest bigger number to Right\n");
	for (i=*top;i>=0;i--){
		int traped=-1;
		for (j=i-1;j>=0;j--){
			if (array[j]>array[i]){
				traped=array[j];
				break;
			}
		}
		if (traped !=-1){
			printf("%d --> %d\n",array[i],array[j]);
		}
		else{
		printf("%d --> -1\n",array[i]);
		}
	}
}
