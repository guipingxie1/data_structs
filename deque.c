/**
 * 	@file: deque.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Deque data structure implementation file
 *	@date: Spring 2016
 *
 */

//#define NDEBUG 					// disable assert statements
#include <assert.h>
#include <stddef.h>				// for NULL definition
#include <stdlib.h>				// for malloc, free

#include "deque.h"


/*	Initialize the deque --- similar to a constructor in C++  */
void init_deque( deque* d ) {
	assert( d && "Deque is not valid" );
	
	d -> array = malloc( 16 * sizeof(void*) );
	d -> size = 0;
	d -> capacity = 16;
	d -> first = 0;
	d -> last = 0;
}


/*	Destroy the deque --- similar to a destructor in C++  */
void destroy_deque( deque* d, int free_data ) {
	assert( d && "Deque is not valid" );
	
	if ( free_data ) {
		int cap = d -> capacity;
		for ( int i = 0; i < cap; ++i ) {
			free( (d -> array)[i] );
			(d -> array)[i] = NULL;
		}
	}
		
	free( d -> array );
	d -> array = NULL;
}


/*	Checks if the deque is empty or not  */
int is_empty_deque( deque* d ) {
	assert( d && "Deque is not valid" );
	
	return ( d -> size == 0 );
}


/*	Returns the size of the deque  */
int get_size_deque( deque* d ) {
	assert( d && "Deque is not valid" );

	return d -> size;			
}


/*	Returns the data at the front of the deque  */
void* front_deque( deque* d ) {
	assert( d && "Deque is not valid" );
	assert( d -> size && "Deque is empty" );
	
	return (d -> array)[d -> first];
}


/*	Returns the data at the back of the deque  */
void* back_deque( deque* d ) {
	assert( d && "Deque is not valid" );
	assert( d -> size && "Deque is empty" );
	
	return (d -> array)[d -> last - 1];
}


/*	Pushes in the data into the back of the deque  */
void push_back_deque( deque* d, void* data ) {
	assert( d && "Deque is not valid" );
	assert( (d -> size < DEQUE_MAX_CAP) && "Too many elements, max of 131072" );
	assert( (d -> size <= d -> capacity) && "Deque management went wrong" );
	
	if ( d -> size == d -> capacity ) 
		resize_deque( d, (d -> capacity) << 1, 0 );	
	
	d -> size += 1;
	(d -> array)[d -> last] = data;
	d -> last = ( 1 + d -> last ) % d -> capacity;
} 


/*	Pushes in the data into the front of the deque  */
void push_front_deque( deque* d, void* data ) {
	assert( d && "Deque is not valid" );
	assert( (d -> size < DEQUE_MAX_CAP) && "Too many elements, max of 131072" );
	assert( (d -> size <= d -> capacity) && "Deque management went wrong" );
	
	if ( d -> size == d -> capacity ) 
		resize_deque( d, (d -> capacity) << 1, 0 );	
	
	d -> size += 1;
	d -> first = ( d -> first + d -> capacity - 1 ) % d -> capacity;
	(d -> array)[d -> first] = data;
} 


/*	Remove the last element (data) of the deque  */
void pop_back_deque( deque* d, int free_data ) {
	assert( d && "Deque is not valid" );
	assert( d -> last && "Cannot pop from empty deque" );
	assert( (d -> first != d -> last) && "Cannot pop from empty deque" );
	
	d -> size -= 1;
	d -> last = ( d -> last + d -> capacity - 1 ) % d -> capacity;
	
	if ( free_data ) 
		free( (d -> array)[d -> last] );

	/*	Sets to NULL because for destroy, we free everything  */
	(d -> array)[d -> last] = NULL;
}


/*	Remove the first element (data) of the deque  */
void pop_front_deque( deque* d, int free_data ) {
	assert( d && "Deque is not valid" );
	assert( (d -> first > -1) && "Cannot pop from empty deque" );
	assert( (d -> first != d -> last) && "Cannot pop from empty deque" );
	
	if ( free_data ) 
		free( (d -> array)[d -> first] );

	/*	Sets to NULL because for destroy, we free everything  */
	(d -> array)[d -> first] = NULL;
	
	d -> size -= 1;
	d -> first = ( 1 + d -> first ) % d -> capacity;
}


/*	Returns the element (data) at the specified index of the deque  */
void* get_elem_deque( deque* d, int pos ) {
	assert( d && "Deque is not valid" );
	assert( (pos > -1 && pos < d -> size) && "Invalid index" );
	
	return (d -> array)[ (pos + d -> first ) % d -> capacity ];
} 


/*	Sets the data at the specified index of the deque  */
void set_elem_deque( deque* d, int pos, void* data, int free_data ) {
	assert( d && "Deque is not valid" );
	assert( (pos > -1 && pos < d -> size) && "Invalid index" );
	
	int idx = (pos + d -> first ) % d -> capacity;
	
	if ( free_data ) 
		free( (d -> array)[idx] );
	
	(d -> array)[idx] = data;
}


// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------


/*	Resizes the deque  */
void resize_deque( deque* d, int new_size, int free_data ) {
	assert( d && "Deque is not valid" );
	assert( (new_size > -1) && "Invalid size, must be non negative" );
	assert( (new_size < DEQUE_MAX_CAP) && "New size can only be up to 131072" );

	int former_cap = d -> capacity;		
	int size = d -> size;
	int head = d -> first;
	d -> capacity = new_size;
	
	void** new_array = malloc( new_size * sizeof(void*) );
	
	/*	Traverse from the front of the deque and copies the data over  */
	for ( int i = 0; i < size; ++i ) 
		new_array[i] = (d -> array)[ (head + i) % former_cap ];
	
	free( d -> array );
	d -> array = new_array;
	
	/*	Reset the first and last values so they correspond to the new array  */
	d -> first = 0;
	d -> last = size;
}


/*	Deletes the entry at the provided position and shifts everything after it  */
void delete_at_deque( deque* d, int pos, int free_data ) {
	assert( d && "Deque is not valid" );
	assert( (pos > -1 && pos <= d -> size) && "Invalid index" );
	
	if ( free_data ) {
		free( (d -> array)[pos] );
		(d -> array)[pos] = NULL;
	}	
	
	/*	Shifting everything backwards  */
	int size = d -> size;
	for ( int i = pos + 1; i <= size; ++i )
		(d -> array)[i - 1] = (d -> array)[i];
		
	d -> size -= 1;	
}


/*	Inserts the entry at the provided position and shifts everything after it  */
void insert_at_deque( deque* d, int pos, void* data ) {
	assert( d && "Deque is not valid" );
	assert( (pos > -1 && pos <= d -> size) && "Invalid index" );

	if ( 1 + d -> size == d -> capacity ) {
		if ( d -> capacity == 0 )
			resize_deque( d, 16, 0 );
		else resize_deque( d, (d -> capacity) << 1, 0 );
	}
	
	/*	Shifting everything forwards  */
	int size = d -> size;
	for ( int i = size; i >= pos; --i )
		(d -> array)[i + 1] = (d -> array)[i];
	
	(d -> array)[pos] = data;	
	d -> size += 1;	
}
