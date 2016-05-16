/**
 * 	@file: queue.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Queue data structure implementation file
 *	@date: Spring 2016
 *
 */
 
#define NDEBUG 					// disable assert statements
#include <assert.h>
#include <stddef.h>				// for NULL definition
#include <stdlib.h>				// for malloc, free

#include "queue.h"


/*	Initialize the queue --- similar to a constructor in C++  */
void init_queue( queue* q ) {
	assert( v && "Queue is not valid" );
	
	v -> array = malloc( 16 * sizeof(void*) );
	v -> size = -1;
	v -> max_size = -1;
	v -> capacity = 16;
}


/*	Destroy the queue --- similar to a destructor in C++  */
void destroy_queue( queue* q, int free_data ) {
	assert( v && "Queue is not valid" );
	
	if ( free_data ) {
		int max = v -> max_size;
		for ( int i = 0; i <= max; ++i ) {
			free( (v -> array)[i] );
			(v -> array)[i] = NULL;
		}
	}
		
	free( v -> array );
	v -> array = NULL;
}


/*	Resizes the queue  */
void resize_queue( queue* q, int new_size, int free_data ) {
	assert( v && "Queue is not valid" );
	assert( (new_size > -1) && "Invalid size, must be non negative" );
	assert( (new_size < VECT_MAX_CAP) && "New size can only be up to 131072" );
	
	if ( v -> size > new_size ) {
		if ( free_data ) {
			int size = v -> size;
			
			for ( int i = new_size; i <= size; ++i ) {
				free( (v -> array)[i] );
				(v -> array)[i] = NULL;
			}
		}
		
		v -> size = new_size - 1;
		v -> max_size = new_size - 1;
	}
		
	v -> capacity = new_size;	
	
	v -> array = realloc( v -> array, new_size * sizeof(void*) );
}


/*	Checks if the queue is empty or not  */
int is_empty_queue( queue* q ) {
	assert( v && "Queue is not valid" );
	
	return ( v -> size == -1 );
}


/*	Returns the size of the queue  */
int get_size_queue( queue* q ) {
	assert( v && "Queue is not valid" );

	/*	Need to add one because it is 0-indexed  */
	return 1 + v -> size;			
}


/*	Returns the data at the front of the queue  */
void* front_queue( queue* q ) {
	assert( v && "Queue is not valid" );
	assert( (v -> size > -1) && "Queue is empty" );
	
	return (v -> array)[0];
}


/*	Returns the data at the back of the queue  */
void* back_queue( queue* q ) {
	assert( v && "Queue is not valid" );
	assert( (v -> size > -1) && "Queue is empty" );
	
	return (v -> array)[v -> size];
}


/*	Pushes in the data into the queue  */
void push_queue( queue* q, void* data ) {
	assert( v && "Queue is not valid" );
	assert( (1 + v -> size < VECT_MAX_CAP) && "Too many elements, max of 131072" );
	assert( (v -> size < v -> capacity) && "Queue management went wrong" );
	
	if ( 1 + v -> size == v -> capacity ) {
		if ( v -> capacity == 0 )
			resize_queue( v, 16, 0 );
		else resize_queue( v, (v -> capacity) << 1, 0 );
	}
	
	v -> size += 1;
	(v -> array)[v -> size] = data;
	
	if ( v -> size > v -> max_size )
		v -> max_size = v -> size;
} 


/*	Remove the last element (data) pushed into the queue  */
void pop_queue( queue* q, int free_data ) {
	assert( v && "Queue is not valid" );
	assert( (v -> size > -1) && "Cannot pop from empty queue" );
	
	if ( free_data ) {
		free( (v -> array)[v -> size] );
		(v -> array)[v -> size] = NULL;
	}
	
	v -> size -= 1;
}


/*	Returns the element (data) at the specified index of the queue  */
void* get_elem_queue( queue* q, int pos ) {
	assert( v && "Queue is not valid" );
	assert( (pos > -1 && pos <= v -> size) && "Invalid index" );
	
	return (v -> array)[pos];
} 


/*	Sets the data at the specified index of the queue  */
void set_elem_queue( queue* q, int pos, void* data, int free_data ) {
	assert( v && "Queue is not valid" );
	assert( (pos > -1 && pos <= v -> size) && "Invalid index" );
	
	if ( free_data ) 
		free( (v -> array)[pos] );
	
	(v -> array)[pos] = data;
}


/*	Deletes the entry at the provided position and shifts everything after it  */
void delete_at_queue( queue* q, int pos, int free_data ) {
	assert( v && "Queue is not valid" );
	assert( (pos > -1 && pos <= v -> size) && "Invalid index" );
	
	if ( free_data ) {
		free( (v -> array)[pos] );
		(v -> array)[pos] = NULL;
	}	
	
	/*	Shifting everything backwards  */
	int size = v -> size;
	for ( int i = pos + 1; i <= size; ++i )
		(v -> array)[i - 1] = (v -> array)[i];
		
	v -> size -= 1;	
}


/*	Inserts the entry at the provided position and shifts everything after it  */
void insert_at_queue( queue* q, int pos, void* data ) {
	assert( v && "Queue is not valid" );
	assert( (pos > -1 && pos <= v -> size) && "Invalid index" );

	if ( 1 + v -> size == v -> capacity ) {
		if ( v -> capacity == 0 )
			resize_queue( v, 16, 0 );
		else resize_queue( v, (v -> capacity) << 1, 0 );
	}
	
	/*	Shifting everything forwards  */
	int size = v -> size;
	for ( int i = size; i >= pos; --i )
		(v -> array)[i + 1] = (v -> array)[i];
	
	(v -> array)[pos] = data;	
	v -> size += 1;	
}
