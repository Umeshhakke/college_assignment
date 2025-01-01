/*
Name: Umesh Pandit Hakke
Class: S.Y (A)
Roll No: 2059

Program to implement bubble Sort
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	printf("Enter the size of data array: ");
	scanf("%d",&size);
	
	int data[size];
	printf("Put the data to the data array: \n");
	
	for (int i=0;i<size;i++)
	{
		scanf("%d",&data[i]);
	}
	
	for (int i=0;i<size-1;i++)
	{
		for (int j=0;j<size-i-1;j++)
		{
			if (data[j]>data[j+1])
			{
				int temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp; 
			}
		}
	}
	
	printf("Sorted data array: \n");
	for (int i=0;i<size;i++)
	{
		printf("%d\t",data[i]);
	}
	return 0;
}
