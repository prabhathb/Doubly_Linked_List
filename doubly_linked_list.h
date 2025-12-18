/*
	Name: doubly_linked_list.h
	Copyright: 
	Author: Prabhath Buddhika
	Date: 05-12-25 09:36
	Description: This header file declares the variables and functions used with the doubly linked list data structure.
*/

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

//declare the structure to hold the data item and the pointers to the next and previous nodes.
struct node{
	int d;
	struct node* next;	
	struct node* previous;
};

//declare the struct node as a user defined data type called list_item.
typedef struct node list_item;

//this vaiable records the number of items available in the linked list.
//this is initially zero and incremented everytime a new item is inserted.
//it decrements everytime an item is removed.
unsigned int number_of_items = 0;

//declare the pointer to the front of the doubly linked list
list_item* front = NULL;
//declare the pointer to the front of the doubly linked list
list_item* rear = NULL;

//initialise the doubly linked list
void init_doubly_linked_list(int data_item);
//insert a node to the front of the doubly linked list
void insert_front(int data_item);
//insert a node to the end of the doubly linked list
void insert_end(int data_item);
//insert a node to the given item number of the doubly linked list
void insert_at(int data_item,unsigned int position);
//remove a node from the front of the doubly linked list
int remove_front();
//remove a node from the end of the doubly linked list
int remove_end();
//remove the node at the given item number of the doubly linked list
int remove_at(unsigned int position);
//get the number of items available in the doubly linked list
int get_number_of_items();
//traverse the doubly linked list from front to rear
void traverse_list_from_front();
//traverse the doubly linked list from rear to front
void traverse_list_from_rear();

#endif

