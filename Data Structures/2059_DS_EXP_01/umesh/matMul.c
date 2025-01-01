//Program of Marix multiplication
//Name:Umesh Pandit Hakke 
//Roll no:- 2059
#include <stdio.h>
int mat1[10][10],mat2[10][10],result[10][10];

void input(){
	int i,j;
	printf("mat1\n");
	for (i=1;i<=3;i++){
		for (j=1;j<=3;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
		printf("mat2\n");
	for (i=1;i<=3;i++){
		for (j=1;j<=3;j++){
			scanf("%d",&mat2[i][j]);
		}
	}
}
void preview(){
	int i,j;
	printf("mat1\n");
	for ( i=1;i<=3;i++){
		for ( j=1;j<=3;j++){
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
		printf("mat2\n");
	for (i=1;i<=3;i++){
		for (j=1;j<=3;j++){
			printf("%d\t",mat2[i][j]);
		}
		printf("\n");
	}
}
int multiply(){
	int i,j,k;
	printf("you have got multi as\n");

			printf("result\n");
	for (i=1;i<=3;i++){
		for (j=1;j<=3;j++){
			result[i][j]=0;
			for (k=1;k<=3;k++){
					result[i][j]=result[i][j]+mat1[i][k]*mat2[k][j];
			}
		}
	}
		for (i=1;i<=3;i++){
		for (j=1;j<=3;j++){
			printf("%d\t",result[i][j]);
		}
		printf("\n");
	}
}
int main(){
	input();
	preview();
	multiply();
	return 0;
}
