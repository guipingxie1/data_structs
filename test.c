/**
 * 	@file: test.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Tests the data structures
 *	@date: Spring 2016
 *
 */
 
#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
#include "stack_ll.h"
#include "stack.h"
#include "queue.h"
#include "deque.h"
#include "priority_queue.h"
#include "vector.h"
#include "set.h"
#include "map.h"
#include "hashtable.h" 

struct tester {
	int k;
	char c;
	double g;
};

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void stack_teststruct_ll_p() {
	stack_ll s;
	init_stack_ll( &s );

	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_stack_ll( &s, x );
	}

	for ( int i = 0; i < 64; ++i ) {
		struct tester* data = top_stack_ll( &s );
		printf("%d, %c, %f ---", data -> k, data -> c, data -> g);
		pop_stack_ll( &s );
		free( data );
	}	
	
	printf("\n");
	
	destroy_stack_ll( &s, 0 );
}

void stack_testint_ll_p() {
	stack_ll s;
	init_stack_ll( &s );

	for ( int i = 0; i < 128; ++i ) 
		push_stack_ll( &s, i );

	for ( int i = 0; i < 128; ++i ) {
		int k = top_stack_ll( &s );
		printf("%d ", k);
		pop_stack_ll( &s );	
	}
	
	printf("\n");
	
	destroy_stack_ll( &s, 0 );
}

void stack_teststruct_ll() {
	stack_ll s;
	init_stack_ll( &s );

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* x = malloc( sizeof(struct tester) );
			x -> k = i;
			x -> c = i % 26 + 'a';
			x -> g = i * i / 3.0;
			push_stack_ll( &s, x );
		}
	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* data = top_stack_ll( &s );
			pop_stack_ll( &s );
			free( data );
		}
	}
	
	destroy_stack_ll( &s, 0 );
}

void stack_testint_ll() {
	stack_ll s;
	init_stack_ll( &s );

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			push_stack_ll( &s, i );
	
		for ( int i = 0; i < 16384; ++i ) 
			pop_stack_ll( &s );
			
		for ( int i = 0; i < 50000; ++i ) 
			push_stack_ll( &s, i );	
			
		for ( int i = 0; i < 25000; ++i ) 
			pop_stack_ll( &s );	
			
		for ( int i = 0; i < 25000; ++i ) 
			push_stack_ll( &s, i );	
			
		for ( int i = 0; i < 50000; ++i ) 
			pop_stack_ll( &s );		
	}
	
	destroy_stack_ll( &s, 0 );
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void stack_teststruct_p() {
	stack s;
	init_stack( &s );
	
	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_stack( &s, x );
	}

	for ( int i = 0; i < 64; ++i ) {
		struct tester* data = top_stack( &s );
		printf("%d, %c, %f ---", data -> k, data -> c, data -> g);
		free( data );
		pop_stack( &s );
	}	
	
	printf("\n");
	
	destroy_stack( &s, 0 );
}

void stack_testint_p() {
	stack s;
	init_stack( &s );

	for ( int i = 0; i < 128; ++i ) 
		push_stack( &s, i );

	for ( int i = 0; i < 128; ++i ) {
		int k = top_stack( &s );
		printf("%d ", k);
		pop_stack( &s );		
	}	
	
	printf("\n");
	
	destroy_stack( &s, 0 );
}

void stack_teststruct() {
	stack s;
	init_stack( &s );

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* x = malloc( sizeof(struct tester) );
			x -> k = i;
			x -> c = i % 26 + 'a';
			x -> g = i * i / 3.0;
			push_stack( &s, x );
		}
	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* data = top_stack( &s );
			pop_stack( &s );
			free( data );
		}
	}
	
	destroy_stack( &s, 0 );
}

void stack_testint() {
	stack s;
	init_stack( &s );
	//resize_stack( &s, 65536 );			// testing speedup

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			push_stack( &s, i );

		for ( int i = 0; i < 16384; ++i ) 
			pop_stack( &s );
			
		//resize_stack(&s, 0);	
			
		for ( int i = 0; i < 50000; ++i ) 
			push_stack( &s, i );	
			
		for ( int i = 0; i < 25000; ++i ) 
			pop_stack( &s );	
			
		for ( int i = 0; i < 25000; ++i ) 
			push_stack( &s, i );	
			
		for ( int i = 0; i < 50000; ++i ) 
			pop_stack( &s );		
	}

	destroy_stack( &s, 0 );
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

int main( int argc, char* argv[] ) {
	assert( argc == 3 );
	
	char* arg = argv[1];
	int k = atoi( argv[2] );			// 1 if we want to print
	
	if ( strcmp(arg, "stackll") == 0 ) {
		if ( !k ) {
			stack_testint_ll();
			stack_teststruct_ll();
		}
		else {
			stack_testint_ll_p();
			stack_teststruct_ll_p();
		}
	}
	else if ( strcmp(arg, "stack") == 0 ) {
		if ( !k ) {
			stack_testint();
			stack_teststruct();
		}
		else {
			stack_testint_p();
			stack_teststruct_p();
		}
	}
	else if ( strcmp(arg, "set") == 0 ) {
		
	}
	else if ( strcmp(arg, "map") == 0 ) {
		
	}
	else if ( strcmp(arg, "vector") == 0 ) {
		
	}
	else if ( strcmp(arg, "queue") == 0 ) {
		
	}
	else if ( strcmp(arg, "pqueue") == 0 ) {
		
	}
	else if ( strcmp(arg, "deque") == 0 ) {
		
	}
	else if ( strcmp(arg, "hash") == 0 ) {
		
	}
	else {
		/*	nothing  */
	}
	
	return 0;
}
