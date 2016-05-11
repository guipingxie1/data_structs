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

/*	Stack cannot be bigger than 65536  */	
#define STACK_MAX_CAP 65536


/**
 * 	The stack struct the user will use
 *	Implemented with an array
 *
 */
typedef struct stack {
	/*	The vector we use to implement the stack  */
	struct vector v;
  
} stack;


/**
 *	Initialize the stack --- similar to a constructor in C++
 *
 * 	@param s: The stack struct we want to operate with
 */
void init_stack( stack* s );


/**
 *	Destroy the stack --- similar to a destructor in C++
 *
 * 	@param s: The stack struct we want to operate with
 */
void destroy_stack( stack* s );


/**
 *	Resizes the stack (call if the max size is known before hand)
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param new_size: The new size we want our stack to be
 */
void resize_stack( stack* s, int new_size );


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
 *
 * 	@param s: The stack struct we want to operate with
 * 	@return The data at the top of the stack
 */
void* top_stack( stack* s );


/**
 *	Pushes in the data into the stack
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param data: The data we want to push into the stack
 */
void push_stack( stack* s, void* data );  


/**
 *	Remove the last element (data) pushed into the stack
 *
 * 	@param s: The stack struct we want to operate with
 */
void pop_stack( stack* s );


/**
 *	Returns the element (data) at the specified index of the stack
 *
 * 	@param s: The stack struct we want to operate with
 * 	@param pos: The index we of the element we want to access
 * 	@return The data at the specified index
 */
void* get_elem_stack( stack* s, int pos ); 


#endif
