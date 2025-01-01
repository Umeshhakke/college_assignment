#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size, key,found=0,i;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	int array[size];
	printf("Enter the element in the array\n");
	for (i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Enter the number you wanted to search in the array: ");
	scanf("%d",&key);
	
	for ( i=0;i<size;i++)
	{
		if (key==array[i])
		{
			found=1;
			break;
		}
	}
	if(!found){
		printf("There is no match found !\n");
	}
	else
	{
		printf("%d\n",array[i]);
	}
	return 0;
}
