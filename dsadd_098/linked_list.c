#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

//NODE STRUCTURE
typedef struct NODE{
	void* data;
	struct NODE* link;
} Node;


//HEAD STRUCTURE
typedef struct HEAD{
	int count;
	Node* next; 
}head;


//CREATES AND INITIALIZES A NEW LIST
head* createList(){
	head* h = (head*)malloc(sizeof(head));
	h->count = 0;
	h->next = NULL;
	return h;
}


//CREATES NEW NODE
Node* createNewNode(void* data){
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL;

	return temp;
}


//INSERTS INTO LIST AT GIVEN POSITION
void insert(head* h, void* d, int position){
	if(h == NULL){
		printf("NoListExistingError: Create a new List first!!!\n");
		return;
	}
	if(h->next == NULL){
		h->next = createNewNode(d);
		h->count++;
	}else{
		Node* newNode = createNewNode(d);
		Node* temp = h->next;
		if(position == 1){
			h->next = newNode;
			newNode->link = temp;
			h->count++;
		}else if(position > h->count + 1 || position < 0){
			printf("IllegalPositionError: Cannot Insert\n");
		}else{
			int count = 1;
			while(count < position - 1){
				temp = temp->link;
				count++;
			}
			newNode->link = temp->link;
			temp->link = newNode;
			h->count++;
		}
	}
}



//DELETES FROM THE LIST ON GIVEN POSITION
void delete(head* h, int position){
	if(h == NULL){
		printf("NoListExistingError: Create a new List first\n");
		return;
	}
	if(h->next == NULL){
		printf("EmptyListError: No elements are present in the list\n");
		return;
	}else{
		Node* temp = h->next;
		if(position == 1){
			h->next = temp->link;
			h->count--;
			free(temp);
		}else if(position > h->count || position < 0){
			printf("IllegalPositionError: Cannot Delete\n");
		}
		else{
			Node* a = temp;
			Node* b = temp -> link;
			int count = 1;
			while(count < position - 1){
				a = a->link;
				b = b->link;
				count++;
			}
			a->link = b->link;
			free(b);
			h->count--;
		}
	}
}

//DELETES ENTIRE LIST AND RETURNS EMPTY HEAD
void deleteList(head* h){
	Node* current = h->next;
	Node* next = current;
	while(next != NULL){
		current = current -> link;
		free(next);
		h->count--;
		next = current;
	}
	h->next = NULL;
}

//SEARCHES A GIVEN VALUE IN THE LIST

bool search(head* h, void* x, bool (*fptr)(void *, void *)){
	Node* temp = h->next;
	while(temp != NULL){
		if((* fptr)(temp->data, x)){
			return true;
		}
		temp = temp->link;
	}
	return false;
}

//GETS A NODE VALUE AT THE GIVEN POSITION

void* valueAt(head* h, int position){
	if(position > h->count || position < 0){
		printf("ERROR: Invalid Position");
		return NULL;
	}else{
		Node *temp = h->next;
		int count = 0;
		while(count < position){
			temp = temp->link;
			count++;
		}
		return temp->data;
	}
}


//COMPARES INT
bool compareInt(void * x, void* y){
	return *(int *)x == *(int *)y;
}

//COMPARES FLOAT
bool compareFloat(void * x, void* y){
	return *(float *)x == *(float *)y;
}

//COMPARES CHAR
bool compareChar(void * x, void* y){
	return *(char *)x == *(char *)y;
}

//COMPARES DOUBLE
bool compareDouble(void * x, void* y){
	return *(double *)x == *(double *)y;
}

//COMPARES LONG
bool compareLong(void * x, void* y){
	return *(long int *)x == *(long int *)y;
}


//DISPLAYS THE GENERIC DATA USING FUNCTION POINTERS
void display(head* h, void (* fptr)(void *)){
	if(h->count == 0){
		printf("The list is empty!!!");
	}else{
		Node* temp = h->next;
		while(temp){
			(* fptr)(temp->data);
			temp = temp->link;
		}
	}
	printf("\n");
}


//DISPLAY INT
void printInt(void* data){
	printf("%d ", *(int *)(data));
}

//DISPLAY FLOAT
void printFloat(void* data){
	printf("%f ", *(float *)(data));
}


//DISPLAY CHAR
void printChar(void* data){
	printf("%c ", *(char *)(data));
}


//DISPLAY DOUBLE
void printDouble(void* data){
	printf("%lf ", *(double *)(data));
}


//DISPLAY LONG
void printLong(void* data){
	printf("%ld ", *(long int *)(data));
}



//TEST MAIN FUNCTION
void main(){
	head* h;
	int choice;
	int position;
	char* data;
	char d;

	do{
		printf("Menu: \n");
		printf("1. Create List\n2. Insert in list\n3. Display List.\n4. Delete\n5. Delete List\n6. Search\n7. Value at\n8. Exit\n\n");

		printf("CHOICE: ");
		scanf("%d", &choice);


		switch (choice){
		case 1:
			h = createList();
			break;
		case 2: 
			printf("POSITION: ");
			scanf("%d", &position);
			printf("DATA: ");
			data = (char *)malloc(sizeof(char));
			scanf(" %c", &d);
			*data = d;
			insert(h, data, position);
			break;
		case 3: 
				display(h, printChar);
				break;
		case 4:
			printf("POSITION: ");
			scanf("%d", &position);
		    delete(h, position);
		    break;
		case 5:
			deleteList(h);
			printf("List Deleted");
			break;
		case 6:
			printf("CHAR: ");
			scanf(" %c", &d);
			data = (char *)malloc(sizeof(char));
			*data = d;
			if(search(h, data, compareChar)){
				printf("FOUND IT!");
			}
			else{
				printf("NOT FOUND!");
			}
			break;
		case 7:
			printf("POSITION: ");
			scanf("%d", &position);
			printf("%c \n", *(char *)(valueAt(h, position)));
		}	

	}while(choice <= 9);

}