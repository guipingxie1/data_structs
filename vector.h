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
 *	Stay consistant with data pushed into the vector  
 *	Please do not modify the struct directly
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
 *			init_vector( v ); 
 *	OR
 *			vector v;
 *			init_vector( &v ); 		
 *
 * 	@param v: The vector struct we want to operate with
 */
void init_vector( vector* v );


/**
 *	Destroy the vector --- similar to a destructor in C++
 *	Do not call any frees on the vector structure yourself 
 *	Do NOT set free_data to nonzero value if data is on the stack, will cause errors
 *
 * 	@param v: The vector struct we want to operate with
 * 	@param free_data: Whether we should free the data or not, 0 - don't free
 */
void destroy_vector( vector* v, int free_data );


/**
 *	Resizes the vector (call if the max size is known before hand)
 *
 * 	@param v: The vector struct we want to operate with
 * 	@param new_size: The new size we want our vector to be
 */
void resize_vector( vector* v, int new_size );


/**
 *	Checks if the vector is empty or not
 *
 * 	@param v: The vector struct we want to operate with
 * 	@return 1 (true) if the vector is empty, 0 (false) otherwise
 */
int is_empty_vector( vector* v );


/**
 *	Returns the size of the vector
 *
 * 	@param v: The vector struct we want to operate with
 * 	@return The size of the vector
 */
int get_size_vector( vector* v );


/**
 *	Returns the data at the front of the vector
 *	Can manipulate the data in place and changes will be reflected in the vector 
 *
 * 	@param v: The vector struct we want to operate with
 * 	@return The data at the front of the vector
 */
void* front_vector( vector* v );


/**
 *	Returns the data at the back of the vector
 *	Can manipulate the data in place and changes will be reflected in the vector 
 *
 * 	@param v: The vector struct we want to operate with
 * 	@return The data at the back of the vector
 */
void* back_vector( vector* v );


/**
 *	Pushes in the data into the vector
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the vectors lifetime 
 *
 * 	@param v: The vector struct we want to operate with
 * 	@param data: The data we want to push into the vector
 */
void push_vector( vector* v, void* data );  


/**
 *	Remove the last element (data) pushed into the vector
 *	This does NOT free the data if it was initialized in the heap
 *	In order to free the data, should call back_vector to get the last element
 *			then free that data and then call pop_vector
 *
 * 	@param v: The vector struct we want to operate with
 */
void pop_vector( vector* v );


/**
 *	Returns the element (data) at the specified index of the vector
 *	vector is 0-indexed therefore the first element is at index 0
 *
 * 	@param v: The vector struct we want to operate with
 * 	@param pos: The index of the element we want to access (0-indexed)
 * 	@return The data at the specified index
 */
void* get_elem_vector( vector* v, int pos ); 


/**
 *	Deletes the entry at the provided position and shifts everything after it
 *	Will free the data if the free_data parameter is non zero
 *	Do NOT set free_data to nonzero value if data is on the stack, will cause errors
 *
 * 	@param v: The vector struct we want to operate with
 * 	@param pos: The index of the element we want to delete (0-indexed)
 * 	@param free_data: Whether we want to free the data at the position
 */
void delete_at_vector( vector* v, int pos, int free_data ); 


/**
 *	Inserts the entry at the provided position and shifts everything after it
 *	Can only insert up to the last element (same as push_vector)
 *	Cannot insert past the end
 *
 * 	@param v: The vector struct we want to operate with
 * 	@param data: The data we want to insert into the vector 
 * 	@param pos: The index of the element we want to insert at (0-indexed)
 */
void insert_at_vector( vector* v, void* data, int pos ); 


#endif
