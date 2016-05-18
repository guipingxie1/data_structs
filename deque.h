/**
 * 	@file: deque.h
 * 	@author: Guiping Xie 
 *
 * 	@description: Deque data structure header file 
 *	@date: Spring 2016
 *
 */
 

#ifndef DEQUE_H 
#define DEQUE_H

/*	Deque cannot be bigger than 131072  */	
#define DEQUE_MAX_CAP 131073


/**
 * 	The deque struct the user will use
 *	Implemented with a circular array
 *	Can only hold up to 131072 elements
 *	Stay consistant with data pushed into the deque  
 *	Please do not modify the struct directly
 *
 */
typedef struct deque {
	/*	The array we use to implement the deque  */
	void** array;
	
	/*	The current size of the array  */	
	int size;

	/*	The maximum capacity of the array  */	
	int capacity;
	
	/*	The first index of the array  */
	int first;
	
	/*	The last index of the array --- may not need, can use first + size  */
	int last;
  
} deque;


/**
 *	Initialize the deque --- similar to a constructor in C++
 *	Can be called with either :
 *			deque* d = malloc( sizeof(deque) );
 *			init_deque( q ); 
 *	OR
 *			deque q;
 *			init_deque( &q ); 		
 *
 * 	@param d: The deque struct we want to operate with
 */
void init_deque( deque* d );


/**
 *	Destroy the deque --- similar to a destructor in C++
 *	Do not call any frees on the deque structure yourself 
 *	Do NOT set free_data to nonzero value if data is on the stack, will cause errors
 *	However user responsible to free the deque struct if it was malloc'd
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param free_data: Whether we should free the data or not, 0 - don't free
 */
void destroy_deque( deque* d, int free_data );


/**
 *	Checks if the deque is empty or not
 *
 * 	@param d: The deque struct we want to operate with
 * 	@return 1 (true) if the deque is empty, 0 (false) otherwise
 */
int is_empty_deque( deque* d );


/**
 *	Returns the size of the deque
 *
 * 	@param d: The deque struct we want to operate with
 * 	@return The size of the deque
 */
int get_size_deque( deque* d );


/**
 *	Returns the data at the front of the deque
 *	Can manipulate the data in place and changes will be reflected in the deque 
 *
 * 	@param d: The deque struct we want to operate with
 * 	@return The data at the front of the deque
 */
void* front_deque( deque* d );


/**
 *	Returns the data at the back of the deque
 *	Can manipulate the data in place and changes will be reflected in the deque 
 *
 * 	@param d: The deque struct we want to operate with
 * 	@return The data at the back of the deque
 */
void* back_deque( deque* d );


/**
 *	Pushes in the data into the back of the deque
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the deques lifetime 
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param data: The data we want to push into the deque
 */
void push_back_deque( deque* d, void* data ); 


/**
 *	Pushes in the data into the front of the deque
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the deques lifetime 
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param data: The data we want to push into the deque
 */
void push_front_deque( deque* d, void* data ); 


/**
 *	Remove the last element (data) of the deque
 *	Will free the data if the free_data param is non zero
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param free_data: Whether we want to free the data (non zero value - free)  
 */
void pop_back_deque( deque* d, int free_data );


/**
 *	Remove the first element (data) of the deque
 *	Will free the data if the free_data param is non zero
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param free_data: Whether we want to free the data (non zero value - free)  
 */
void pop_front_deque( deque* d, int free_data );


/**
 *	Returns the element (data) at the specified index of the deque
 *	Deque is 0-indexed therefore the first element is at index 0
 *	Can also manipulate the data directly through this function call
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param pos: The index of the element we want to access (0-indexed)
 * 	@return The data at the specified index
 */
void* get_elem_deque( deque* d, int pos ); 


/**
 *	Sets the data at the specified index of the deque
 *	Deque is 0-indexed therefore the first element is at index 0
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param pos: The index of the element we want to set (0-indexed)
 * 	@param data: The data 
 * 	@param free_data: Whether we want to free the data at the position 
 */
void set_elem_deque( deque* d, int pos, void* data, int free_data ); 


// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------


/**
 *	Deletes the entry at the provided position and shifts everything after it
 *	Will free the data if the free_data parameter is non zero
 *	Do NOT set free_data to nonzero value if data is on the stack, will cause errors
 *
 *	NOTE: VERY SLOW
 *
 *	*** IMPORTANT NOTE *** : Not implemented yet
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param pos: The index of the element we want to delete (0-indexed)
 * 	@param free_data: Whether we want to free the data at the position
 */
void delete_at_deque( deque* d, int pos, int free_data ); 


/**
 *	Inserts the entry at the provided position and shifts everything after it
 *	Can only insert up to the last element (same as push_deque)
 *	Cannot insert past the end
 *
 *	NOTE: VERY SLOW
 *
 *	*** IMPORTANT NOTE *** : Not implemented yet 
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param pos: The index of the element we want to insert at (0-indexed) 
 * 	@param data: The data we want to insert into the deque 
 */
void insert_at_deque( deque* d, int pos, void* data ); 


/**
 *	Resizes the deque (call if the max size is known before hand)
 *
 *	*** IMPORTANT NOTE *** : Private function for now, may cause unexpected results
 *
 *	Can also free all the data if the new_size is smaller than the original size
 *	To do this set the free_data parameter to a non-zero value
 *	Only deletes data up to the current size (get_size_deque()), everything else
 *			that was put onto the deque and removed will not be freed 
 *
 *	Resizing to new_size of 0 is equivalent to clearing the whole deque
 *
 * 	@param d: The deque struct we want to operate with
 * 	@param new_size: The new size we want our deque to be
 * 	@param free_data: Whether we want to free the data if new_size if smaller
 */
void resize_deque( deque* d, int new_size, int free_data );


#endif
