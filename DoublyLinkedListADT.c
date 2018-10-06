#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
}NODE;
typedef struct slist
{
	NODE* st;
}SLIST;
NODE *createnode(int no)
{
	NODE *a;
	a=(NODE *)malloc(sizeof(NODE));
	a->data=no;
	a->next=NULL;
	a->prev=NULL;
	return a;
}
void createlist(SLIST *t)
{
	NODE *a,*c;
	int n;
	while(1)
	{	
		printf("\nEnter no:\n");
		scanf("%d",&n);
		if(n==0)
			break;
		a=createnode(n);
		if(t->st==NULL)
		{
			t->st=a;
		}
		else
		{
			c->next=a;
			a->prev=c;
		}
		c=a;
	}
}
NODE* getlastnode(SLIST *t)
{
	NODE *a=t->st;
	while(a->next!=NULL)
		a=a->next;
	return a;
}
void display(SLIST *t)
{
	NODE *a=t->st;
	while(a!=NULL)
	{
		printf("%d ",a->data);
		a=a->next;
	}
}
int search(SLIST *t, int n)
{
	NODE *a=getlastnode(t);
	while(a!=NULL)
	{
		if(a->data==n)
			break;
		a=a->prev;
	}
	if(a==NULL)
		return 0;
	else
		return 1;
} 
void main()
{
	SLIST p;
	int d;
	p.st=NULL;
	createlist(&p);
	display(&p);
	d=search(&p,1);
	if(d==1)
		printf("\nfound\n");
	else
		printf("\nNot found\n");
	
}








