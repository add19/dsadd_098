#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0 
typedef struct node
{
    int data;
    struct node* next;
}NODE;
typedef struct head
{	
	NODE* head;
	NODE* rear;
	int cnt;
}HEAD;

HEAD* initHead()
{
 	HEAD* headStruct=(HEAD* )malloc(sizeof(HEAD));
 	headStruct->head=NULL;
 	headStruct->rear=NULL;
 	headStruct->cnt=0;
 	return headStruct; 
}
 
 
NODE* createNode(int n)
{
	NODE* temp=(NODE* )malloc(sizeof(NODE));
	temp->data=n;
	temp->next=NULL;
	return temp;
}

void addAtBegin(HEAD* headStruct,int n)
{
	NODE* temp=createNode(n); //Allocating memory for a node 
	temp->next=(headStruct)->head;
	if((headStruct)->head==NULL)
	{
		(headStruct)->rear=temp;
		(headStruct)->head=temp;
		(headStruct)->cnt++;
		return;
	} //adding node before the previous node
	(headStruct)->head=temp;
	headStruct->rear->next=temp;
	(headStruct)->cnt++;
	
}

void addAtEnd(HEAD* headStruct,int n)
{
	NODE* temp=createNode(n);
	if((headStruct)->head==NULL)
	{
		(headStruct)->head=temp;
		(headStruct)->rear=temp;
		(headStruct)->cnt++;
		return;
	}
	(headStruct)->rear->next=temp;
	(headStruct)->rear=temp;
	temp->next=headStruct->head;
	(headStruct)->cnt++;
	return;
}

void disp(HEAD* headStruct)
{
	NODE* temp;int i=0;
	temp=headStruct->head;
	printf("\nThe list is: ");
	while(i<headStruct->cnt)
	{
		printf("%d ",temp->data);
		temp=temp->next;
		i++;
	}

}

int deleteNode(HEAD* headStruct,int n)
{	
	NODE* temp=headStruct->head;
	if(headStruct->cnt==1)
	{
		if(temp->data==n)
		{
			headStruct->head=NULL;
			headStruct->rear=NULL;
			headStruct->cnt=0;
			free(temp);
			return true;
		}
			return false;
	}
	NODE* temp1=headStruct->head;
	int i,cntr=0;
	if(headStruct->head==NULL)
	{
		return false;
	}
	while(temp->data!=n)
	{
		temp=temp->next;
		cntr++;
	}
	//cntr - No. of nodes before the node to delete;  
	for(i=0; i<cntr-1; i++)
	{
		temp1=temp1->next;
	}
	/*if(temp->next==NULL)
	{
		headStruct->rear=temp1;
	}*/
	temp1->next=temp->next;
	free(temp);
	return true;	
}

int DeleteAtBegin(HEAD* headStruct)
{
	NODE* temp=headStruct->head;
	if(headStruct->head==NULL)
	return false;
	if(headStruct->cnt==1)
	{
		headStruct->head=NULL;
		headStruct->rear=NULL;
		headStruct->cnt=0;
		free(temp);
		return true;	
	}
	headStruct->head=headStruct->head->next;
	headStruct->rear->next=headStruct->head;
	free(temp);
	return true;
}

int DeleteAtEnd(HEAD* headStruct)
{
	int i;
	NODE* temp=headStruct->head;
	if(headStruct->head==NULL)
	return false;
	if(headStruct->cnt==1)
	{
		headStruct->head=NULL;
		headStruct->rear=NULL;
		headStruct->cnt=0;
		free(temp);
		return true;	
	}
	for(i=0; i<headStruct->cnt-2; i++)
	{
		temp=temp->next;
	}
	headStruct->rear=temp;
	NODE* temp1=temp->next;
	temp->next=headStruct->head;
	free(temp1);
	return true;
}


