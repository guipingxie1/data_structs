/**
 * 	@file: stack.h
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure (array implementation) header file
 *	@date: Spring 2016
 *
 */
 

#ifndef STACK_H 
#define STACK_H

/*	Stack cannot be bigger than 131072  */	
#define STACK_MAX_CAP 131073


/**
 * 	The stack struct the user will use
 *	Implemented with an array
 *	Can only hold up to 131072 elements
 *	Stay consistant with data pushed into the stack  
 *	Please do not modify the struct directly
 *
 */
typedef struct stack {
	/*	The array we use to implement the vector  */
	void** array;
	
	/*	The current size of the array  */	
	int size;
	
	/*	The maximum size of the array (used for freeing)  */	
	int max_size;

	/*	The maximum capacity of the array  */	
	int capacity;
  
} stack;


/**
 *	Initialize the stack --- similar to a constructor in C++
 *	Can be called with either :
 *			stack* s = malloc( sizeof(stack) );
 *			init_stack( s ); 
 *	OR
 *			stack s;
 *			init_stack( &s ); 		
 *
 * 	@param s: The stack struct we want to operate with
 */
void init_stack( stack* s );


/**
 *	Destroy the stack --- similar to a destructor in C++
 *	Do not call any frees on the stack structure yourself 
 *	However user responsible to free the stack struct if it was malloc'd 
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param free_data: Whether we should free the data or not, 0 - don't free
 *											Do NOT free when data is on the stack 
 */
void destroy_stack( stack* s, int free_data );


/**
 *	Resizes the stack (call if the max size is known before hand)
 *	Can also free all the data if the new_size is smaller than the original size
 *	To do this set the free_data parameter to a non-zero value 
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param new_size: The new size we want our stack to be
 * 	@param free_data: Whether we want to free the data if new_size if smaller 
 */
void resize_stack( stack* s, int new_size, int free_data );


/**
 *	Checks if the stack is empty or not
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return 1 (true) if the stack is empty, 0 (false) otherwise
 */
int is_empty_stack( stack* s );


/**
 *	Returns the size of the stack
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return The size of the stack
 */
int get_size_stack( stack* s );


/**
 *	Returns the data at the top of the stack
 *	Can manipulate the data in place and changes will be reflected in the stack 
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return The data at the top of the stack
 */
void* top_stack( stack* s );


/**
 *	Pushes in the data into the stack
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the stacks lifetime 
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param data: The data we want to push into the stack
 */
void push_stack( stack* s, void* data );  


/**
 *	Remove the last element (data) pushed into the stack
 *	Will free the data if the free_data param is non zero
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param free_data: Whether we want to free the data (non zero value - free) 
 */
void pop_stack( stack* s, int free_data );


/**
 *	Returns the element (data) at the specified index of the stack
 *	Stack is 0-indexed therefore the first element is at index 0
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param pos: The index we of the element we want to access (0-indexed)
 * 	@return The data at the specified index
 */
void* get_elem_stack( stack* s, int pos ); 


#endif
