/*Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array.*/
/*
Name: Umesh Pandit Hakke
Class: S.Y
Roll No: 2059
Div: A
*/
#include <stdio.h>

int* nearest_left_smaller_element(int array[], int size);
int* nearest_right_smaller_element(int array[], int size);
int* Maximum_difference(int element[],int rl[],int size);

int main()
{
	int array[20];
	int a,b;
	printf("enter the number of element you want to add to the array: ");
	scanf("%d",&a);
	printf("enter the element in array: ");
	for (int i=0;i<a;i++)							//Taking the input of array elements
	{
		scanf("%d",&array[i]);
	}
	printf("You have the array:\n{");
	for (int i=0;i<a;i++)							//printing to check weather the element has scaned properly
	{	
		printf("%d,",array[i]);
	}
	printf("}\n\n");
	
	int* ls =nearest_left_smaller_element(array,a);		//ls is a pointer and it is assigned by the array1 pointer returned by the function
	
	 printf("Nearest smaller elements to the left:\n{"); // Printing  the result which is stored int the array1
    for (int i = 0; i < a; i++) 
	{
        printf("%d,", ls[i]);
    }
    printf("}\n\n");
    
	int* rs =nearest_right_smaller_element(array,a);	//ls is a pointer and it is assigned by the array pointer returned by the function
	
	 printf("Nearest smaller elements to the left:\n{"); // Printing  the result which is stored int the array1
    for (int i = 0; i < a; i++)
	{
        printf("%d,", rs[i]);
    }
    printf("}\n\n");
  	Maximum_difference(ls,rs,a);						//Function call 
	return 0;
}

int* nearest_left_smaller_element(int array[], int size)		//Function to check nearest right smaller element
 {
    static int array1[20];
    
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = i - 1; j >= 0; j--)
		{
            if (array[j] < array[i]) 				//check weaether the number is smaller or not
			{
                array1[i] = array[j];  // Store the nearest smaller element
                found = 1;
                break;
            }
        }
        
        if (found!=1) {
            array1[i] = 0;  // If no element found lower than the current number then store the value as 0
        }
    }

   return array1;
}
int* nearest_right_smaller_element(int array[], int size) 		//Function to check nearest right smaller element
{
    static int array2[20];
    
    for (int i = 0; i < size; i++) 
	{
        int found = 0;
        for (int j = i; j < size; j++) 
		{
            if (array[j] < array[i]) 
			{
                array2[i] = array[j];  // Store the nearest smaller element
                found = 1;
                break;
            }
        }
        
        if (found!=1) 
		{
            array2[i] = 0;  // If no element found lower than the current number then store the value as 0
        }
    }

   return array2;
}
int* Maximum_difference(int ls[],int rs[],int size)
{
	int max_num=0,max_val=0;
	for (int i=0;i<size;i++)
	{
		max_num=ls[i]-rs[i];		//calculate the difference between nearest left element and nearest right element
		if (max_num>max_val)		//checking between calculated value and  stored value 
		{
			max_val=max_num;		//if calculated value is higher than stored value then calculated value is placed
		}
	}
	printf("Maximum absolute difference : %d",max_val);		//printing maximum absolute difference
	return 0;
}
/*
Input : arr[] = {2, 1, 8}
Output : 1
Left smaller  LS[] {0, 0, 1}
Right smaller RS[] {1, 0, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 1

*/
