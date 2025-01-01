//Program of fibonacci Series
//Name:Umesh Pandit Hakke 
//Roll no:- 2059
#include <stdio.h>
int fibo(int n){
	if (n==1){
		return 1;
	}
	else if (n==2){
		return 2;
	}
	else {
		return fibo(n-1)+fibo(n-2);
	}
}
int main(){
	int a,b,i;
	printf("program to fibonacci number\n");
	printf("enter number\n");
	scanf("%d",&a);
	for(i=1;i<=a;i++){
	b=fibo(i);
	printf("%d  ",b);	
	}
	return 0;
}
