#include "doubly_linked_list.h"

//initialise the doubly linked list
void init_doubly_linked_list(int data_item){
	list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list. This will be the first node of the list.
	a->d = data_item;										//new node stores the new data item.
	//This is the only node in the list so far. Therefore...
	a->next = NULL;											//next of the new node is NULL.
	a->previous = NULL;										//previous of the new node is also NULL.
	front = a;												//front points tothe only node of the list.
	rear = a;												//rear also points to the ony node of the list.
	number_of_items++;										//increment the number of items in the list.
}
//insert a node to the front of the doubly linked list
void insert_front(int data_item){
	list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list.
	a->d = data_item;										//new node stores the new data item.
	a->next = front;										//next of the new node points to the front of the list.
	front->previous = a;									//prvious of the front node of the list is adjusted to the new node.
	front= a;												//front is now adjusted to point to the new node.
	a->previous = NULL;										//previous of the new node points to NULL.
	number_of_items++;										//increment the number of items in the list.	
}

//insert a node to the end of the doubly linked list
void insert_end(int data_item){
	list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list.
	a->d = data_item;										//new node stores the new data item.
	a->next = NULL;											//next of the new node points to NULL.
	a->previous = rear;										//previous of the new node points to the rear of the list.
	rear->next = a;											//next of the node at the reaar end points to the new node.
	rear = a;												//rear points to the new node added at the end of the list.
	number_of_items++;										//increment the number of items in the list.	
}

//insert a node to the given item number of the doubly doubly linked list
void insert_at(int data_item,unsigned int position){
	unsigned int p = 0;											//a locla variable to navigate through the list.
	list_item* x;												//new variable for a node is declared.
	//if the position is less than or equal the mid point of the list...
	if(position <= (number_of_items>>1)){
		x = front;												//x is set to the front of the list.						
		for(p=0; p<position-2; p++){							//node at two positions before the position points to the node before the position.
			x = x->next;										//x is updated to the address of the next node in the list.
		}
		list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list.
		a->d = data_item;										//new node stores the new data item.
		a->next = x->next;										//next of new node points to the next of x which the item at the 'position'.
		a->previous = x;										//previous of new node points to the x.
		x->next->previous = a;									//previous of the next of x points to the new node.
		x->next = a;											//next of x is assigned the address of the new node.
		number_of_items++;										//increment the number of items in the list.
	}
	//else if the position is less than or equal the mid point of the list...
	else if (position <= number_of_items){
		x = rear;												//x is set to the rear of the list.
		for(p=number_of_items-1; p>position-2; p--){			//node at two positions before the position points to the node before the position.
			x = x->previous;									//x is updated to the address of the next node in the list.
		}
		list_item* a = (list_item*)malloc(sizeof(list_item));	//allocate memory for the new node of the list.
		a->d = data_item;										//new node stores the new data item.
		a->next = x->next;										//next of new node points to the next of x which the item at the 'position'.
		a->previous = x;										//previous of new node points to the x.
		x->next->previous = a;									//previous of the next of x points to the new node.
		x->next = a;											//next of x is assigned the address of the new node.
		number_of_items++;										//increment the number of items in the list.
	}
	//if the given 'position' is beyond the last element of the list, ignore the insert and report error to the user.
	else{
		printf("Insert Failed! List is shorter than the given position number (%d).\n",position);
	}		
}

//remove a node from the front of the doubly linked list
int remove_front(){
	int dt = -1;							//return -1 by default if the list is empty.
	list_item* x = front;					//new variable for a node is set to point to the front of the list.
	if(x != NULL){							//ensure front isnot NULL. If NULL, the list must be empty.
		dt = x->d;							//local variable dt stores the data item stored in the list item.
		front = x->next;					//adjust the front to point to the next item of the list.
		front->previous = NULL;				//previous of the node pointed by front is NULL.
		free(x);							//delete the node pointed by x and free its memory.
	}
	number_of_items--;						//decrement the number of items in the list.
	return dt;								//return the data item to the caller function.
}

//remove a node from the end of the doubly linked list
int remove_end(){
	int dt = -1;							//return -1 by default if the list is empty.
	list_item* x = rear;					//new variable for a node is set to point to the front of the list.
	if(x != NULL){							//ensure front isnot NULL. If NULL, the list must be empty.
		dt = x->d;							//local variable dt stores the data item stored in the list item.
		rear = x->previous;					//adjust the front to point to the next item of the list.
		rear->next = NULL;					//previous of the node pointed by front is NULL.
		free(x);							//delete the node pointed by x and free its memory.
	}
	number_of_items--;						//decrement the number of items in the list.
	return dt;								//return the data item to the caller function.	
}

//remove the node at the given item number of the doubly linked list
int remove_at(unsigned int position){
	int dt = -1;												//return -1 by default in case of an extreme condition.
	unsigned int p = 0;											//a locla variable to navigate through the list.
	list_item *x,*y;											//two variables for nodes are declared.
	//if the position is less than or equal the mid point of the list...
	if(position <= (number_of_items>>1)){
		x = front;												//x is set to the front of the list.						
		for(p=0; p<position-2; p++){							//node at two positions before the position points to the node before the position.
			x = x->next;										//x is updated to the address of the next node in the list.
		}
		y = x->next;											//y points to the node next to x. Hence, y is the node to be removed.
		dt = y->d;												//local variable dt stores the data item stored in the list item.
		x->next = y->next;										//next of x points to the next of y which is the part of the list beyond the position.
		y->next->previous = x;									//previous of the next of x points to x.
		free(y);												//delete the node y which is at position and free its memory.
		number_of_items--;										//decrement the number of items in the list.
	}
	//else if the position is less than or equal the mid point of the list...
	else if (position <= number_of_items){
		x = rear;												//x is set to the rear of the list.
		for(p=number_of_items-1; p>position-2; p--){			//node at two positions before the position points to the node before the position.
			x = x->previous;									//x is updated to the address of the next node in the list.
		}
		y = x->next;											//y points to the node next to x. Hence, y is the node to be removed.
		dt = y->d;												//local variable dt stores the data item stored in the list item.
		x->next = y->next;										//next of x points to the next of y which is the part of the list beyond the position.
		y->next->previous = x;									//previous of the next of x points to x.
		free(y);												//delete the node y which is at position and free its memory.
		number_of_items--;										//decrement the number of items in the list.
	}
	//if the given 'position' is beyond the last element of the list, ignore the insert and report error to the user.
	else{
		printf("Remove Failed! List is shorter than the given position number (%d).\n",position);
	}	
	return dt;													//return the data item to the caller function.		
}

//get the number of items available in the doubly linked list
int get_number_of_items(){
	return number_of_items;
}

//traverse the doubly linked list from front to rear
void traverse_list_from_front(){
	printf("List is traversed from front!\n");
	unsigned int p = 1;					//a locla variable to indicate the position  in the list.
	list_item* x = front;				//new variable for a node is set to point to the front of the list.
	while(x != NULL){					//until the end of the list is found...
		printf("(%d) %d\n",p,x->d);		//print the data item of each node with the index.
		x = x->next;					//go to the next node.
		p++;							//increment p.
	}
}

//traverse the doubly linked list from rear to front
void traverse_list_from_rear(){
	printf("List is traversed from rear!\n");
	unsigned int p = number_of_items;	//a locla variable to indicate the position  in the list.
	list_item* x = rear;				//new variable for a node is set to point to the front of the list.
	while(x != NULL){					//until the end of the list is found...
		printf("(%d) %d\n",p,x->d);		//print the data item of each node with the index.
		x = x->previous;				//go to the previous node.
		p--;							//decrement p.
	}
}