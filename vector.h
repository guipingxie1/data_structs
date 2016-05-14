/**
 * 	@file: vector.h
 * 	@author: Guiping Xie 
 *
 * 	@description: Vector data structure header file 
 *	@date: Spring 2016
 *
 */
 

#ifndef VECTOR_H 
#define VECTOR_H

/*	Vector cannot be bigger than 131072  */	
#define vector_MAX_CAP 131073


/**
 * 	The vector struct the user will use
 *	Implemented with an array
 *	Can only hold up to 131072 elements
 *	Stay consistant with data pushed into the stack  
 *
 */
typedef struct vector {
	/*	The array we use to implement the vector  */
	void** array;
	
	/*	The current size of the array  */	
	int size;
	
	/*	The maximum size of the array (used for freeing)  */	
	int max_size;

	/*	The maximum capacity of the array  */	
	int capacity;
  
} vector;


/**
 *	Initialize the vector --- similar to a constructor in C++
 *	Can be called with either :
 *			vector* v = malloc( sizeof(vector) );
 *			init_vector( s ); 
 *	OR
 *			vector s;
 *			init_vector( &s ); 		
 *
 * 	@param s: The vector struct we want to operate with
 */
void init_vector( vector* v );


/**
 *	Destroy the vector --- similar to a destructor in C++
 *	Do not call any frees on the vector structure yourself 
 *
 * 	@param s: The vector struct we want to operate with
 * 	@param free_data: Whether we should free the data or not, 0 - don't free
 *											Do NOT free when data is on the vector 
 */
void destroy_vector( vector* v, int free_data );


/**
 *	Resizes the vector (call if the max size is known before hand)
 *
 * 	@param s: The vector struct we want to operate with
 * 	@param new_size: The new size we want our vector to be
 */
void resize_vector( vector* v, int new_size );


/**
 *	Checks if the vector is empty or not
 *
 * 	@param s: The vector struct we want to operate with
 * 	@return 1 (true) if the vector is empty, 0 (false) otherwise
 */
int is_empty_vector( vector* v );


/**
 *	Returns the size of the vector
 *
 * 	@param s: The vector struct we want to operate with
 * 	@return The size of the vector
 */
int get_size_vector( vector* v );


/**
 *	Returns the data at the front of the vector
 *	Can manipulate the data in place and changes will be reflected in the vector 
 *
 * 	@param s: The vector struct we want to operate with
 * 	@return The data at the front of the vector
 */
void* front_vector( vector* v );


/**
 *	Returns the data at the back of the vector
 *	Can manipulate the data in place and changes will be reflected in the vector 
 *
 * 	@param s: The vector struct we want to operate with
 * 	@return The data at the back of the vector
 */
void* back_vector( vector* v );


/**
 *	Pushes in the data into the vector
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the vectors lifetime 
 *
 * 	@param s: The vector struct we want to operate with
 * 	@param data: The data we want to push into the vector
 */
void push_vector( vector* v, void* data );  


/**
 *	Remove the last element (data) pushed into the vector
 *	This does NOT free the data if it was initialized in the heap
 *	In order to free the data, should call back_vector to get the last element
 *			then free that data and then call pop_vector
 *
 * 	@param s: The vector struct we want to operate with
 */
void pop_vector( vector* v );


/**
 *	Returns the element (data) at the specified index of the vector
 *	vector is 0-indexed therefore the first element is at index 0
 *
 * 	@param s: The vector struct we want to operate with
 * 	@param pos: The index we of the element we want to access (0-indexed)
 * 	@return The data at the specified index
 */
void* get_elem_vector( vector* v, int pos ); 


#endif
