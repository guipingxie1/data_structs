/**
 * 	@file: queue.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Queue data structure implementation file
 *	@date: Spring 2016
 *
 */
 
//#define NDEBUG 					// disable assert statements
#include <assert.h>
#include <stddef.h>				// for NULL definition
#include <stdlib.h>				// for malloc, free

#include "queue.h"


/*	Initialize the queue --- similar to a constructor in C++  */
void init_queue( queue* q ) {
	assert( q && "Queue is not valid" );
	
	q -> array = malloc( 16 * sizeof(void*) );
	q -> size = -1;
	q -> capacity = 16;
	q -> first = -1;
	q -> last = -1;
}


/*	Destroy the queue --- similar to a destructor in C++  */
void destroy_queue( queue* q, int free_data ) {
	assert( q && "Queue is not valid" );
	
	if ( free_data ) {
		int cap = q -> capacity;
		for ( int i = 0; i <= cap; ++i ) {
			free( (q -> array)[i] );
			(q -> array)[i] = NULL;
		}
	}
		
	free( q -> array );
	q -> array = NULL;
}


/*	Resizes the queue  */
void resize_queue( queue* q, int new_size, int free_data ) {
	assert( q && "Queue is not valid" );
	assert( (new_size > -1) && "Invalid size, must be non negative" );
	assert( (new_size < QUEUE_MAX_CAP) && "New size can only be up to 131072" );

/*	
	if ( q -> size > new_size ) {
		if ( free_data ) {
			int size = q -> size;
			
			for ( int i = new_size; i <= size; ++i ) {
				free( (q -> array)[i] );
				(q -> array)[i] = NULL;
			}
		}
		
		q -> size = new_size - 1;
	}
*/

	int former_cap = q -> capacity;		
	int size = q -> size;
	int head = q -> first;
	q -> capacity = new_size;
	
	void** new_array = malloc( new_size * sizeof(void*) );
	
	/*	Traverse from the front of the queue and copies the data over  */
	for ( int i = 0; i < size; ++i ) 
		new_array[i] = (q -> array)[ (head + i) % former_cap ];
	
	free( q -> array );
	q -> array = new_array;
	
	/*	Reset the first and last values so they correspond to the new array  */
	q -> first = 0;
	q -> last = size;
}


/*	Checks if the queue is empty or not  */
int is_empty_queue( queue* q ) {
	assert( q && "Queue is not valid" );
	
	return ( q -> size == -1 );
}


/*	Returns the size of the queue  */
int get_size_queue( queue* q ) {
	assert( q && "Queue is not valid" );

	/*	Need to add one because it is 0-indexed  */
	return 1 + q -> size;			
}


/*	Returns the data at the front of the queue  */
void* front_queue( queue* q ) {
	assert( q && "Queue is not valid" );
	assert( (q -> size > -1) && "Queue is empty" );
	assert( (q -> first != -1) && "Queue is empty" );
	
	return (q -> array)[q -> first];
}


/*	Returns the data at the back of the queue  */
void* back_queue( queue* q ) {
	assert( q && "Queue is not valid" );
	assert( (q -> size > -1) && "Queue is empty" );
	assert( (q -> last != -1) && "Queue is empty" );
	
	return (q -> array)[q -> last];
}


/*	Pushes in the data into the queue  */
void push_queue( queue* q, void* data ) {
	assert( q && "Queue is not valid" );
	assert( (1 + q -> size < QUEUE_MAX_CAP) && "Too many elements, max of 131072" );
	assert( (q -> size < q -> capacity) && "Queue management went wrong" );
	
	/*	Can also use if first = last and some other conditions  */
	if ( 1 + q -> size == q -> capacity ) {
	/*
		if ( q -> capacity == 0 )
			resize_queue( q, 16, 0 );
		else resize_queue( q, (q -> capacity) << 1, 0 );
	*/
	
		resize_queue( q, (q -> capacity) << 1, 0 );	
	}
	
	q -> size += 1;
	q -> last = ( 1 + q -> last ) % q -> capacity;
	(q -> array)[q -> last] = data;
} 


/*	Remove the last element (data) pushed into the queue  */
void pop_queue( queue* q, int free_data ) {
	assert( q && "Queue is not valid" );
	assert( (q -> first > -1) && "Cannot pop from empty queue" );
	assert( (q -> first != q -> last) && "Cannot pop from empty queue" );
	
	if ( free_data ) 
		free( (q -> array)[q -> first] );

	/*	Sets to NULL because for destroy, we free everything  */
	(q -> array)[q -> first] = NULL;
	
	q -> size -= 1;
	q -> first = ( 1 + q -> first ) % q -> capacity;
}


/*	Returns the element (data) at the specified index of the queue  */
void* get_elem_queue( queue* q, int pos ) {
	assert( q && "Queue is not valid" );
	assert( (pos > -1 && pos <= q -> size) && "Invalid index" );
	
	return (q -> array)[ (pos + q -> first ) % q -> capacity ];
} 


/*	Sets the data at the specified index of the queue  */
void set_elem_queue( queue* q, int pos, void* data, int free_data ) {
	assert( q && "Queue is not valid" );
	assert( (pos > -1 && pos <= q -> size) && "Invalid index" );
	
	int idx = (pos + q -> first ) % q -> capacity;
	
	if ( free_data ) 
		free( (q -> array)[idx] );
	
	(q -> array)[idx] = data;
}


/*	Deletes the entry at the provided position and shifts everything after it  */
void delete_at_queue( queue* q, int pos, int free_data ) {
	assert( q && "Queue is not valid" );
	assert( (pos > -1 && pos <= q -> size) && "Invalid index" );
	
	if ( free_data ) {
		free( (q -> array)[pos] );
		(q -> array)[pos] = NULL;
	}	
	
	/*	Shifting everything backwards  */
	int size = q -> size;
	for ( int i = pos + 1; i <= size; ++i )
		(q -> array)[i - 1] = (q -> array)[i];
		
	q -> size -= 1;	
}


/*	Inserts the entry at the provided position and shifts everything after it  */
void insert_at_queue( queue* q, int pos, void* data ) {
	assert( q && "Queue is not valid" );
	assert( (pos > -1 && pos <= q -> size) && "Invalid index" );

	if ( 1 + q -> size == q -> capacity ) {
		if ( q -> capacity == 0 )
			resize_queue( q, 16, 0 );
		else resize_queue( q, (q -> capacity) << 1, 0 );
	}
	
	/*	Shifting everything forwards  */
	int size = q -> size;
	for ( int i = size; i >= pos; --i )
		(q -> array)[i + 1] = (q -> array)[i];
	
	(q -> array)[pos] = data;	
	q -> size += 1;	
}
