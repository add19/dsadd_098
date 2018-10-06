//LinkedList ADT - addAtBegin, atEnd, Insert at i, Delete node by value, DeleteAtBegin, DeleteAtEnd.
/* This ADT has a Struct head {ptr to HeadNode, ptr to RearNode, count of elements in  list}.
 * Use of structure for head helps reduce complexity while adding at end - No need to travel till end.
 * Also, we only need to pass value of headStruct to access its 
 * phead, prear as we need to sustain phead and prear not headStruct, 
   So no pointer to headStruct needed - No double pointer.  	
 */
#include<stdlib.h>
#include<stdio.h>
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
	temp->next=(headStruct)->head; //adding node before the previous node
	if((headStruct)->head==NULL)
	{
		(headStruct)->rear=temp;
	}
	(headStruct)->cnt++;
	(headStruct)->head=temp;
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
	(headStruct)->cnt++;
	return;
}

void disp(HEAD* headStruct)
{
	NODE* temp;
	temp=headStruct->head;
	printf("\nThe list is: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}

}

void insert(HEAD* headStruct,int n, int pos)
{
	int i;
	NODE* tempHead= (headStruct)->head;
	NODE* temp=createNode(n);
	if(pos==1)
	{
		temp->next=(headStruct)->head;
		(headStruct)->head=temp;
		if((headStruct)->rear==NULL)
		(headStruct)->rear=temp;
		headStruct->cnt++;			//temp1: Previous node ; temp: New node
		return;     	
	}
	for(i=0; i<n-2;i++)		
	{
		tempHead=tempHead->next;
		if(tempHead->next==NULL)
		break;	
	}
	temp->next=tempHead->next;
	if(tempHead->next==NULL)
		headStruct->rear=temp;
	tempHead->next=temp;
	headStruct->cnt++;

}

int deleteNode(HEAD* headStruct,int n)
{
	NODE* temp=headStruct->head;
	if(headStruct->cnt==1)
	{
		if(headStruct->head->data==n)
		{
			headStruct->head=NULL;
			headStruct->rear=NULL;
			headStruct->cnt=0;
			headStruct->cnt--;
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
	if(temp->next==NULL)
	{
		headStruct->rear=temp1;
	}
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
	headStruct->cnt--;
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
	headStruct->cnt--;
	free(temp->next);
	return true;
}
