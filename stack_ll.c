/**
 * 	@file: stack_ll.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure 
 *	@date: Spring 2016
 *
 */
 

#include "stack_ll.h"

/**
 * 	Using a linked list implementation
 *
 */
typedef struct linked_list {
	/* The data the node will be holding */
	void* data;

	/* The next pointer --- can be NULL to indicate the end */	
  struct linked_list* next; 
  
} list_node;



/* Initialize the stack --- similar to a constructor in C++ */
void init_stack( stack_ll* s ) {
	
}


/* Destroy the stack --- similar to a destructor in C++ */
void destroy_stack( stack_ll* s ) {

}


/* Checks if the stack is empty or not */
int is_empty( stack_ll* s ) {

}


/* Returns the size of the stack */
int get_size( stack_ll* s ) {

}


/* Returns the data at the top of the stack */
void* top( stack_ll* s ) {

}


/* Pushes in the data into the stack */
void push( stack_ll* s, void* data ) {

} 


/* Remove the last element (data) pushed into the stack */
void pop( stack_ll* s ) {

}


/* Returns the element (data) at the specified index of the stack */
void* get_elem( stack_ll* s, int pos ) {

} 
