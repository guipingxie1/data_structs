/**
 * 	@file: stack.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Stack data structure 
 *	@date: Spring 2016
 *
 */
 

#include "stack.h"

/**
 * 	Using a linked list implementation
 *
 */
typedef struct linked_list {
	/* The data the node with be holding */
	void* data;

	/* The next pointer --- can be NULL to indicate the end */	
  struct linked_list* next; 
  
} list_node;



