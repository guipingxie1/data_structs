/**
 * 	@file: stack_ll.h
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure (linked list implementation) header file
 *	@date: Spring 2016
 *
 */
 

#ifndef STACKLL_H 
#define STACKLL_H

/* 	Stack cannot be bigger than 65536  */	
#define STACKLL_MAX_CAP 65536


/**
 * 	The stack struct the user will use
 *	Implemented with a linked list
 *
 */
typedef struct stack_ll {
	/* 	The tail of the linked list struct  */	
	struct linked_list* tail;
	
	/* 	The head of the linked list struct (used for iterating)  */	
	struct linked_list* head;
	
	/**
	 * 	The permanent head of the linked list struct 
	 * 	Used to indicate all malloc'd blocks since we use
	 *	a lazy allocation method for increased performance
	 */	
	struct linked_list* perm_head;

	/* The current size of the stack */		
	int size;
  
} stack_ll;


/**
 *	Initialize the stack --- similar to a constructor in C++
 *	Can be called with either :
 *			stack_ll* s = malloc( sizeof(stack_ll) );
 *			init_stack_ll( s ); 
 *	OR
 *			stack_ll s;
 *			init_stack_ll( &s ); 		
 *
 * 	@param s: The stack struct we want to operate with
 */
void init_stack_ll( stack_ll* s );


/**
 *	Destroy the stack --- similar to a destructor in C++
 *	Do not call any frees on the stack_ll structure yourself
 *
 * 	@param s: The stack struct we want to operate with
 */
void destroy_stack_ll( stack_ll* s );


/**
 *	Checks if the stack is empty or not
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return 1 (true) if the stack is empty, 0 (false) otherwise
 */
int is_empty_stack_ll( stack_ll* s );


/**
 *	Returns the size of the stack
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return The size of the stack
 */
int get_size_stack_ll( stack_ll* s );


/**
 *	Returns the data at the top of the stack
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return The data at the top of the stack
 */
void* top_stack_ll( stack_ll* s );


/**
 *	Pushes in the data into the stack
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the stacks lifetime
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param data: The data we want to push into the stack
 */
void push_stack_ll( stack_ll* s, void* data );  


/**
 *	Remove the last element (data) pushed into the stack
 *
 * 	@param s: The stack struct we want to operate with
 */
void pop_stack_ll( stack_ll* s );


/**
 *	Returns the element (data) at the specified index of the stack
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param pos: The index we of the element we want to access
 * 	@return The data at the specified index
 */
void* get_elem_stack_ll( stack_ll* s, int pos ); 


#endif
