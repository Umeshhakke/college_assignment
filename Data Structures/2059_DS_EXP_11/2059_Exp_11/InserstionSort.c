/*
Name: Umesh Pandit Hakke
Class: S.Y (A)
Roll No: 2059

Program to implement Insertion Sort
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size,i,j;
	printf("Enter the size of data array: ");
	scanf("%d",&size);
	
	int data[size];
	printf("Enter the element to the data array: \n");
	
	for (i=0;i<size;i++)
	{
		scanf("%d",&data[i]);
	}
	
	for (i=0 ; i<size ; i++)
	{
		for (j=i ; j>=0 ; j--)
		{
			if (data[j]<data[j-1])
			{
				int temp = data [j];
					data[j] = data [j-1];
					data[j-1] = temp;
			}
		}
	}
	
	printf("Sorted data array: \n");
	for (i=0 ; i<size ; i++)
	{
		printf("%d\t",data[i]);
	}
}
