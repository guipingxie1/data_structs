/**
 * 	@file: stack.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure 
 *	@date: Spring 2016
 *
 */
 
#define NDEBUG 					// disable assert statements
#include <assert.h>
#include <stddef.h>				// for NULL definition
#include <stdlib.h>				// for malloc, free

#include "stack.h"


/*	Initialize the stack --- similar to a constructor in C++  */
void init_stack( stack* s ) {
	assert( s && "Stack is not valid" );
	
	s -> array = malloc( 16 * sizeof(void*) );
	s -> size = 0;
	s -> max_size = 0;
	s -> capacity = 16;
}


/*	Destroy the stack --- similar to a destructor in C++  */
void destroy_stack( stack* s, int free_data ) {
	assert( s && "Stack is not valid" );
	
	if ( free_data ) {
		int max = s -> max_size;
		for ( int i = 0; i < max; ++i ) {
			free( (s -> array)[i] );
			(s -> array)[i] = NULL;
		}
	}
		
	free( s -> array );
	s -> array = NULL;
}


/*	Resizes the stack  */
void resize_stack( stack* s, int new_size ) {
	assert( s && "Stack is not valid" );
	assert( (new_size > -1) && "Invalid size, must be non negative" );
	assert( (new_size < STACK_MAX_CAP) && "New size can only be up to 131072" );
	
	if ( s -> size > new_size ) {
		s -> size = new_size;
		s -> max_size = new_size;
	}
		
	s -> capacity = new_size;	
	
	s -> array = realloc( s -> array, new_size * sizeof(void*) );
}


/*	Checks if the stack is empty or not  */
int is_empty_stack( stack* s ) {
	assert( s && "Stack is not valid" );
	
	return ( s -> size == 0 );
}


/*	Returns the size of the stack  */
int get_size_stack( stack* s ) {
	assert( s && "Stack is not valid" );

	return s -> size;			
}


/*	Returns the data at the top of the stack  */
void* top_stack( stack* s ) {
	assert( s && "Stack is not valid" );
	assert( s -> size && "Stack is empty" );
	
	return (s -> array)[s -> size - 1];
}


/*	Pushes in the data into the stack  */
void push_stack( stack* s, void* data ) {
	assert( s && "Stack is not valid" );
	assert( (s -> size < STACK_MAX_CAP) && "Too many elements, max of 131072" );
	assert( (s -> size <= s -> capacity) && "Stack management went wrong" );
	
	if ( s -> size == s -> capacity ) {
		if ( s -> capacity == 0 )
			resize_stack( s, 16 );
		else resize_stack( s, (s -> capacity) << 1 );
	}
	
	(s -> array)[s -> size] = data;
	s -> size += 1;
	
	if ( s -> size > s -> max_size )
		s -> max_size = s -> size;
} 


/*	Remove the last element (data) pushed into the stack  */
void pop_stack( stack* s ) {
	assert( s && "Stack is not valid" );
	assert( s -> size && "Cannot pop from empty stack" );
	
	s -> size -= 1;
}


/*	Returns the element (data) at the specified index of the stack  */
void* get_elem_stack( stack* s, int pos ) {
	assert( s && "Stack is not valid" );
	assert( (pos > -1 && pos < s -> size) && "Invalid index" );
	
	return (s -> array)[pos];
} 
