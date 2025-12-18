#include <stdio.h>
#include <stdlib.h>
//#include "doubly_linked_list.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	init_doubly_linked_list(6);
	insert_front(5);
	insert_front(4);
	insert_front(2);
	insert_front(1);
	printf("Test Case 01: Insert from Front.\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	insert_end(7);
	insert_end(9);
	insert_end(10);
	printf("Test Case 02: Insert from Rear.\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	insert_at(3,3);
	printf("Test Case 03.1: Insert at (3).\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	insert_at(8,8);
	printf("Test Case 03.2: Insert at (8).\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	remove_front();
	printf("Test Case 04: Remove from Front.\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	remove_end();
	printf("Test Case 05: Remove from End.\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	remove_at(3);
	printf("Test Case 06.1: Remove at (3).\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	remove_at(6);
	printf("Test Case 06.2: Remove at (6).\n");
	traverse_list_from_front();
	traverse_list_from_rear();
	printf("Test Case 07: Insert at (15).\n");
	insert_at(15,15);
	traverse_list_from_front();
	traverse_list_from_rear();
	printf("Test Case 08: Remove at (15).\n");
	remove_at(15);
	traverse_list_from_front();
	traverse_list_from_rear();
	return 0;
}