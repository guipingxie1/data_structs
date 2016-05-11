/**
 * 	@file: stack.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure 
 *	@date: Spring 2016
 *
 */
 

#include "stack.h"

typedef struct vector {
	/*	The array we use to implement the vector  */
	void** array;
	
	/*	The current size of the array  */	
	int size;

	/*	The maximum capacity of the array  */	
	int capacity;
	
} vector;



/*	Initialize the stack --- similar to a constructor in C++  */
void init_stack( stack* s ) {
	
}


/*	Destroy the stack --- similar to a destructor in C++  */
void destroy_stack( stack* s ) {

}


/*	Resizes the stack  */
void resize_stack( stack* s, int new_size ) {

}


/*	Checks if the stack is empty or not  */
int is_empty_stack( stack* s ) {

}


/*	Returns the size of the stack  */
int get_size_stack( stack* s ) {

}


/*	Returns the data at the top of the stack  */
void* top_stack( stack* s ) {

}


/*	Pushes in the data into the stack  */
void push_stack( stack* s, void* data ) {

} 


/*	Remove the last element (data) pushed into the stack  */
void pop_stack( stack* s ) {

}


/*	Returns the element (data) at the specified index of the stack  */
void* get_elem_stack( stack* s, int pos ) {

} 
