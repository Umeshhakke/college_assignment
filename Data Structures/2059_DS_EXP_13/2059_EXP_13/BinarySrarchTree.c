#include <stdio.h>
#include <stdlib.h>
struct node {
	struct node * lchild;
	int data;
	struct node * rchild;
};
typedef struct node NODE;
NODE *root = NULL ;
NODE *create(NODE *p,int data);
int main()
{
	int data,b;
	printf("Program to implement Binary search tree: \n");
	do {
		printf("1.Create node \n2.Inorder \n3.Preorder \n4.Postorder\n");
		scanf("%d",&b);
		switch(b)
		{
			case 1: 
			printf("Enter the data\n");
			scanf("%d",&data);
			root = create (root,data);
			break;
			case 2:
				inorder(root);
				printf("\n\n");
				break;
			case 3:
				preorder(root);
				printf("\n\n");
				break;
			case 4:
				postorder(root);
				printf("\n\n");
				break;
			case 5:
				printf("exiting\n");
				break;
				default :
				printf("Invalid LocationS\n");	
		}
	}while (b!=5);
	return 0;
}

NODE *create(NODE *p,int data)
{
	if (p==NULL)
	{
		p = (NODE *) malloc(sizeof(NODE));
		p->data=data;
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	else if(data<p->data)
	{
		p->lchild = create (p->lchild,data);
	}
	else {
		p->rchild = create (p->rchild,data);
	}
	return p;
}

void inorder(NODE *p)
{
	if (p!=NULL)
	{
		inorder(p->lchild);
		printf("%d\t",p->data);
		inorder(p->rchild);
	}
}
void preorder(NODE *p)
{
	if (p!=NULL)
	{
		printf("%d\t",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void postorder(NODE *p)
{
	if (p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d\t",p->data);
	}
}
