/**
 * 	@file: stack_ll.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure 
 *	@date: Spring 2016
 *
 */
 
#include <assert.h>

#include "stack_ll.h"

/**
 * 	Using a linked list implementation
 *
 */
typedef struct linked_list {
	/*	The data the node will be holding  */
	void* data;

	/*	The next pointer --- can be NULL to indicate the end  */	
  struct linked_list* next; 
  
  /*	The previous pointer (used for popping)  */	
  struct linked_list* prev; 
  
} list_node;



/*	Initialize the stack --- similar to a constructor in C++  */
void init_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
	s -> size = 0;
	s -> tail = NULL;
	s -> head = NULL;
	s -> perm_head = NULL;
}


/*	Destroy the stack --- similar to a destructor in C++  */
void destroy_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
		
}


/*	Checks if the stack is empty or not  */
int is_empty_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
	return ( s -> size == 0 );
}


/*	Returns the size of the stack  */
int get_size_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
}


/*	Returns the data at the top of the stack  */
void* top_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
}


/*	Pushes in the data into the stack  */
void push_stack_ll( stack_ll* s, void* data ) {	
	assert( s && "Stack is not valid" );
	
	if ( s -> perm_head == NULL ) {
		assert( (s -> tail == s -> head == NULL) && "Stack management went wrong" );
		
		list_node* node = malloc( sizeof(list_node) );
		node -> data = data;
		node -> next = NULL;
		node -> prev = NULL;
		s -> perm_head = s -> head = s -> tail = node;
	}
	else {
		/**
		 *	We do not free the list_nodes after a pop 
		 *	so there still may be existing list_nodes after the tail
		 *	We use these existing list_nodes instead of allocating more
		 *	memory since it improves performance
		 */
		if ( s -> tail -> next != NULL ) {
			list_node* node = s -> tail -> next;
			node -> data = data;
			s -> tail = node;
		}
		else {
			list_node* node = malloc( sizeof(list_node) );
			node -> data = data;
			node -> next = NULL;
			node -> prev = s -> tail;
			s -> tail = node;
		} 
	}
	
	s -> size += 1;
} 


/** 
 *	Remove the last element (data) pushed into the stack 
 *	Does not free the last list_node until we destroy
 *	This is to increase performance
 */
void pop_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	assert( (s -> tail != NULL) && "Cannot pop from empty stack" );
	
	s -> tail = s -> prev;
	s -> size -= 1;
	
	if ( s -> tail == NULL )		// no need?
		s -> head == NULL;
}


/*	Returns the element (data) at the specified index of the stack  */
void* get_elem_stack_ll( stack_ll* s, int pos ) {
	assert( s && "Stack is not valid" );
	assert( (pos > -1 && pos <= size) && "Invalid index" );
	
} 
