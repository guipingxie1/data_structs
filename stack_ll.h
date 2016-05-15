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

/* 	Stack cannot be bigger than 131072  */	
#define STACKLL_MAX_CAP 131072


/**
 * 	The stack struct the user will use
 *	Implemented with a linked list
 *	Can only hold up to 131072 elements
 *	Stay consistant with data pushed into the stack 
 *	Please do not modify the struct directly 
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
 *	Do NOT call any frees on the stack_ll structure yourself
 *	However user responsible to free the stack_ll struct if it was malloc'd 
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param free_data: Whether we should free the data or not, 0 - don't free
 *											Do NOT free when data is on the stack
 */
void destroy_stack_ll( stack_ll* s, int free_data );


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
 *	Can manipulate the data in place and changes will be reflected in the stack
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
 *	Will free the data if the free_data param is non zero
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param free_data: Whether we want to free the data (non zero value - free)  
 */
void pop_stack_ll( stack_ll* s, int free_data );


/**
 *	Returns the element (data) at the specified index of the stack
 *	Stack is 0-indexed therefore the first element is at index 0
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param pos: The index we of the element we want to access (0-indexed)
 * 	@return The data at the specified index
 */
void* get_elem_stack_ll( stack_ll* s, int pos ); 


#endif
