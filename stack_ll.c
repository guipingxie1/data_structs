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
void init_stack_ll( stack_ll* s ) {
	s -> size = 0;
	s -> tail = NULL;
	s -> head = NULL;
}


/* Destroy the stack --- similar to a destructor in C++ */
void destroy_stack_ll( stack_ll* s ) {
	
}


/* Checks if the stack is empty or not */
int is_empty_stack_ll( stack_ll* s ) {

}


/* Returns the size of the stack */
int get_size_stack_ll( stack_ll* s ) {

}


/* Returns the data at the top of the stack */
void* top_stack_ll( stack_ll* s ) {

}


/* Pushes in the data into the stack */
void push_stack_ll( stack_ll* s, void* data ) {
	if ( s -> head == NULL ) {
		s -> head = malloc( sizeof
	}
} 


/* 
 *	Remove the last element (data) pushed into the stack 
 *	Does not free the last list_node until we destroy
 *	This is to increase performance
 */
void pop_stack_ll( stack_ll* s ) {

}


/* Returns the element (data) at the specified index of the stack */
void* get_elem_stack_ll( stack_ll* s, int pos ) {

} 
