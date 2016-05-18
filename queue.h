/**
 * 	@file: queue.h
 * 	@author: Guiping Xie 
 *
 * 	@description: Queue data structure header file 
 *	@date: Spring 2016
 *
 */
 

#ifndef QUEUE_H 
#define QUEUE_H

/*	Queue cannot be bigger than 131072  */	
#define QUEUE_MAX_CAP 131073


/**
 * 	The queue struct the user will use
 *	Implemented with a circular array
 *	Can only hold up to 131072 elements
 *	Stay consistant with data pushed into the queue  
 *	Please do not modify the struct directly
 *
 */
typedef struct queue {
	/*	The array we use to implement the queue  */
	void** array;
	
	/*	The current size of the array  */	
	int size;

	/*	The maximum capacity of the array  */	
	int capacity;
	
	/*	The first index of the array  */
	int first;
	
	/*	The last index of the array --- may not need, can use first + size  */
	int last;
  
} queue;


/**
 *	Initialize the queue --- similar to a constructor in C++
 *	Can be called with either :
 *			queue* q = malloc( sizeof(queue) );
 *			init_queue( q ); 
 *	OR
 *			queue q;
 *			init_queue( &q ); 		
 *
 * 	@param q: The queue struct we want to operate with
 */
void init_queue( queue* q );


/**
 *	Destroy the queue --- similar to a destructor in C++
 *	Do not call any frees on the queue structure yourself 
 *	Do NOT set free_data to nonzero value if data is on the stack, will cause errors
 *	However user responsible to free the queue struct if it was malloc'd
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param free_data: Whether we should free the data or not, 0 - don't free
 */
void destroy_queue( queue* q, int free_data );


/**
 *	Checks if the queue is empty or not
 *
 * 	@param q: The queue struct we want to operate with
 * 	@return 1 (true) if the queue is empty, 0 (false) otherwise
 */
int is_empty_queue( queue* q );


/**
 *	Returns the size of the queue
 *
 * 	@param q: The queue struct we want to operate with
 * 	@return The size of the queue
 */
int get_size_queue( queue* q );


/**
 *	Returns the data at the front of the queue
 *	Can manipulate the data in place and changes will be reflected in the queue 
 *
 * 	@param q: The queue struct we want to operate with
 * 	@return The data at the front of the queue
 */
void* front_queue( queue* q );


/**
 *	Returns the data at the back of the queue
 *	Can manipulate the data in place and changes will be reflected in the queue 
 *
 * 	@param q: The queue struct we want to operate with
 * 	@return The data at the back of the queue
 */
void* back_queue( queue* q );


/**
 *	Pushes in the data into the queue
 *	Does NOT create a copy of the data passed in
 *	Therefore the data should remain in scope for as long as the queues lifetime 
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param data: The data we want to push into the queue
 */
void push_queue( queue* q, void* data );  


/**
 *	Remove the first element (data) pushed into the queue
 *	Will free the data if the free_data param is non zero
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param free_data: Whether we want to free the data (non zero value - free)  
 */
void pop_queue( queue* q, int free_data );


/**
 *	Returns the element (data) at the specified index of the queue
 *	Queue is 0-indexed therefore the first element is at index 0
 *	Can also manipulate the data directly through this function call
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param pos: The index of the element we want to access (0-indexed)
 * 	@return The data at the specified index
 */
void* get_elem_queue( queue* q, int pos ); 


/**
 *	Sets the data at the specified index of the queue
 *	Queue is 0-indexed therefore the first element is at index 0
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param pos: The index of the element we want to set (0-indexed)
 * 	@param data: The data 
 * 	@param free_data: Whether we want to free the data at the position 
 */
void set_elem_queue( queue* q, int pos, void* data, int free_data ); 


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
 * 	@param q: The queue struct we want to operate with
 * 	@param pos: The index of the element we want to delete (0-indexed)
 * 	@param free_data: Whether we want to free the data at the position
 */
void delete_at_queue( queue* q, int pos, int free_data ); 


/**
 *	Inserts the entry at the provided position and shifts everything after it
 *	Can only insert up to the last element (same as push_queue)
 *	Cannot insert past the end
 *
 *	NOTE: VERY SLOW
 *
 *	*** IMPORTANT NOTE *** : Not implemented yet 
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param pos: The index of the element we want to insert at (0-indexed) 
 * 	@param data: The data we want to insert into the queue 
 */
void insert_at_queue( queue* q, int pos, void* data ); 


/**
 *	Resizes the queue (call if the max size is known before hand)
 *
 *	*** IMPORTANT NOTE *** : Private function for now, may cause unexpected results
 *
 *	Can also free all the data if the new_size is smaller than the original size
 *	To do this set the free_data parameter to a non-zero value
 *	Only deletes data up to the current size (get_size_queue()), everything else
 *			that was put onto the queue and removed will not be freed 
 *
 *	Resizing to new_size of 0 is equivalent to clearing the whole queue
 *
 * 	@param q: The queue struct we want to operate with
 * 	@param new_size: The new size we want our queue to be
 * 	@param free_data: Whether we want to free the data if new_size if smaller
 */
void resize_queue( queue* q, int new_size, int free_data );


#endif
