#include <stdio.h>
#include <stdlib.h>
int array[100];
int b[100];
void merge(int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	while(i<=mid && j<=high)
	{
		if (array[i]<array[j])
		{
			b[k]=array[i];
			i++;
		}
		else 
		{
			b[k]=array[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		b[k]=array[i];
		i++;
		k++;
	}
	while(j<=high){
		b[k]=array[j];
		j++;
		k++;
	}
	for (int z=low;z<=high;z++)
	{
		array[z]=b[z];
	}
}
void mergsort(int low,int high)
{
	if (low<high)
	{
		int mid = (low+high)/2;
		mergsort(low,mid);
		mergsort(mid+1,high);
		merge(low,mid,high);
	}
}

int main()
{
	int size;
	printf("Enter how many elements you want to enter : ");
	scanf("%d",&size);
	printf("Enter the elements to array: \n");
	for (int i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	int low=0;
	int high=size-1;
	mergsort(low,high);
	for (int i=0;i<size;i++)
	{
		printf("%d\t",b[i]);
	}
	
	return 0;
}
