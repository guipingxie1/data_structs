/**
 * 	@file: stack_ll.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure 
 *	@date: Spring 2016
 *
 */
 
//#define NDEBUG 					// disable assert statements
#include <assert.h>
#include <stddef.h>				// for NULL definition
#include <stdlib.h>				// for malloc, free
#include <stdio.h> 

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
void destroy_stack_ll( stack_ll* s, int free_data ) {
	assert( s && "Stack is not valid" );
		
	list_node* node = s -> perm_head;
	list_node* copy = NULL;
	
	if ( free_data ) {
		while ( node != NULL ) {
			//printf("%p ", node);
			free( node -> data );
			copy = node;
			node = node -> next;
			free( copy );
		}
	}
	else {
		while ( node != NULL ) {
			//printf("%p ", node);
			copy = node;
			node = node -> next;
			free( copy );
		}
	}
}


/*	Checks if the stack is empty or not  */
int is_empty_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
	return ( s -> size == 0 );
}


/*	Returns the size of the stack  */
int get_size_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
	return s -> size;
}


/*	Returns the data at the top of the stack  */
void* top_stack_ll( stack_ll* s ) {
	assert( s && "Stack is not valid" );
	
	list_node* node = s -> tail;
	assert( node && "Cannot get top element, stack is empty" );
	
	return node -> data;
}


/*	Pushes in the data into the stack  */
void push_stack_ll( stack_ll* s, void* data ) {	
	assert( s && "Stack is not valid" );
	assert( (s -> size < STACKLL_MAX_CAP) && "Too many elements, max of 65536" );
	
	/*	This will only be true the first time we push  */
	if ( s -> perm_head == NULL ) {		
		list_node* node = malloc( sizeof(list_node) );
		node -> data = data;
		node -> next = NULL;
		node -> prev = NULL;
		s -> perm_head = s -> head = s -> tail = node;
	}
	else if ( s -> size == 0 ) {
		/*	Case where we initialized the stack but popped everything out of it  */
		list_node* node = s -> perm_head;
		node -> data = data;
		s -> tail = node;
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
			s -> tail -> next = node;
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
	assert( s -> tail && "Cannot pop from empty stack" );
	
	s -> tail = s -> tail -> prev;
	s -> size -= 1;
}


/*	Returns the element (data) at the specified index of the stack  */
void* get_elem_stack_ll( stack_ll* s, int pos ) {
	assert( s && "Stack is not valid" );
	assert( (pos > -1 && pos <= s -> size) && "Invalid index" );
	
	int idx = 0;
	list_node* node = s -> head;
	assert( node && "Stack is empty" );
	
	while ( idx != pos ) {
		assert( node -> next && "Stack management went wrong" );
		
		node = node -> next;
		++idx;
	}
	
	return node -> data;
} 
