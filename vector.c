/**
 * 	@file: vector.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Vector data structure implementation file
 *	@date: Spring 2016
 *
 */
 
#define NDEBUG 					// disable assert statements
#include <assert.h>
#include <stddef.h>				// for NULL definition
#include <stdlib.h>				// for malloc, free

#include "vector.h"


/*	Initialize the vector --- similar to a constructor in C++  */
void init_vector( vector* v ) {
	assert( v && "vector is not valid" );
	
	v -> array = malloc( 16 * sizeof(void*) );
	v -> size = 0;
	v -> max_size = 0;
	v -> capacity = 16;
}


/*	Destroy the vector --- similar to a destructor in C++  */
void destroy_vector( vector* v, int free_data ) {
	assert( v && "vector is not valid" );
	
	if ( free_data ) {
		int max = v -> max_size;
		for ( int i = 0; i < max; ++i ) {
			free( (v -> array)[i] );
			(v -> array)[i] = NULL;
		}
	}
		
	free( v -> array );
	v -> array = NULL;
}


/*	Resizes the vector  */
void resize_vector( vector* v, int new_size ) {
	assert( v && "vector is not valid" );
	assert( (new_size > -1) && "Invalid size, must be non negative" );
	assert( (new_size < vector_MAX_CAP) && "New size can only be up to 131072" );
	
	if ( v -> size > new_size ) {
		v -> size = new_size;
		v -> max_size = new_size;
	}
		
	v -> capacity = new_size;	
	
	v -> array = realloc( v -> array, new_size * sizeof(void*) );
}


/*	Checks if the vector is empty or not  */
int is_empty_vector( vector* v ) {
	assert( v && "vector is not valid" );
	
	return ( v -> size == 0 );
}


/*	Returns the size of the vector  */
int get_size_vector( vector* v ) {
	assert( v && "vector is not valid" );

	return v -> size;			
}


/*	Returns the data at the front of the vector  */
void* front_vector( vector* v ) {
	assert( v && "vector is not valid" );
	assert( v -> size && "vector is empty" );
	
	return (v -> array)[0];
}


/*	Returns the data at the back of the vector  */
void* back_vector( vector* v ) {
	assert( v && "vector is not valid" );
	assert( v -> size && "vector is empty" );
	
	return (v -> array)[v -> size - 1];
}


/*	Pushes in the data into the vector  */
void push_vector( vector* v, void* data ) {
	assert( v && "vector is not valid" );
	assert( (v -> size < vector_MAX_CAP) && "Too many elements, max of 131072" );
	assert( (v -> size <= v -> capacity) && "vector management went wrong" );
	
	if ( v -> size == v -> capacity ) {
		if ( v -> capacity == 0 )
			resize_vector( v, 16 );
		else resize_vector( v, (v -> capacity) << 1 );
	}
	
	(v -> array)[v -> size] = data;
	v -> size += 1;
	
	if ( v -> size > v -> max_size )
		v -> max_size = v -> size;
} 


/*	Remove the last element (data) pushed into the vector  */
void pop_vector( vector* v ) {
	assert( v && "vector is not valid" );
	assert( v -> size && "Cannot pop from empty vector" );
	
	v -> size -= 1;
}


/*	Returns the element (data) at the specified index of the vector  */
void* get_elem_vector( vector* v, int pos ) {
	assert( v && "vector is not valid" );
	assert( (pos > -1 && pos <= v -> size) && "Invalid index" );
	
	return (v -> array)[pos];
} 


/*	Sets the data at the specified index of the vector  */
void set_elem_vector( vector* v, int pos, void* data ) {
	assert( v && "vector is not valid" );
	assert( (pos > -1 && pos <= v -> size) && "Invalid index" );
	
	(v -> array)[pos] = data;
}


/*	Deletes the entry at the provided position and shifts everything after it  */
void delete_at_vector( vector* v, int pos, int free_data ) {

}


/*	Inserts the entry at the provided position and shifts everything after it  */
void insert_at_vector( vector* v, int pos, void* data ) {

}

