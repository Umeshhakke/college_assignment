#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	int array[size],high=size-1,low=0,flag=0,mid,key;
	printf("Enter the element to array\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Enter the element to find : ");
	scanf("%d",&key);
	while(low<=high)
	{
		mid = (low+high)/2;
		if (key == array[mid])
		{
			flag = 1;
			break;
		}
		else if(key<array[mid])
		{
			high = mid-1;
		}
		else 
		{
			low = mid +1 ;
		}
	}
	if (!flag)
	{
		printf("Unsucessfull Search\n");
	}
	else
	{
		printf("Search found \n");
	}
	return 0;
}
