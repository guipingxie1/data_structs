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
		pop_stack_ll( &s, 1 );
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
		pop_stack_ll( &s, 0 );	
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
	
		for ( int i = 0; i < 4096; ++i ) 
			pop_stack_ll( &s, 1 );
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
			pop_stack_ll( &s, 0 );
			
		for ( int i = 0; i < 40000; ++i ) 
			push_stack_ll( &s, i );	
			
		for ( int i = 0; i < 20000; ++i ) 
			pop_stack_ll( &s, 0 );	
			
		for ( int i = 0; i < 20000; ++i ) 
			push_stack_ll( &s, i );	
			
		for ( int i = 0; i < 40000; ++i ) 
			pop_stack_ll( &s, 0 );		
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
		pop_stack( &s, 1 );
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
		pop_stack( &s, 0 );		
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
	
		for ( int i = 0; i < 4096; ++i ) 
			pop_stack( &s, 1 );
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
			pop_stack( &s, 0 );
			
		//resize_stack(&s, 0);	
			
		for ( int i = 0; i < 40000; ++i ) 
			push_stack( &s, i );	
			
		for ( int i = 0; i < 20000; ++i ) 
			pop_stack( &s, 0 );	
			
		for ( int i = 0; i < 20000; ++i ) 
			push_stack( &s, i );	
			
		for ( int i = 0; i < 40000; ++i ) 
			pop_stack( &s, 0 );		
	}

	destroy_stack( &s, 0 );
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void vector_teststruct() {
	vector v;
	init_vector( &v );

	int t = 4;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* x = malloc( sizeof(struct tester) );
			x -> k = i;
			x -> c = i % 26 + 'a';
			x -> g = i * i / 3.0;
			push_vector( &v, x );
		}
	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* x = get_elem_vector( &v, i ); 
			x -> k = i << 1;	
		}
	}
	
	destroy_vector( &v, 1 );
	
	vector vv;
	init_vector( &vv );
	
	for ( int i = 0; i < 512; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_vector( &vv, x );
	}
	
	resize_vector( &vv, 0, 1 );	
	destroy_vector( &vv, 0 );
}

void vector_testint() {
	vector v;
	init_vector( &v );
	
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) 
			push_vector( &v, i );
	
		for ( int i = 0; i < 4096; ++i ) {			
			int k = get_elem_vector( &v, i );
			k *= (i >> 1);
			set_elem_vector( &v, i, k, 0 );
		}
			
		for ( int i = 0; i < 4096; ++i ) 
			delete_at_vector( &v, get_size_vector(&v) - 1, 0 );
			
		for ( int i = 0; i < 16000; ++i ) 
			push_vector( &v, i );
			
		for ( int i = 0; i < 16000; ++i ) 
			set_elem_vector( &v, i, (int)0, 0 );
			
		for ( int i = 0; i < 32; ++i )
			insert_at_vector( &v, 0, 1 );
			
		for ( int i = 0; i < 32; ++i )
			delete_at_vector( &v, 0, 0 );	
			
		resize_vector( &v, 0, 0 );				
	}
	
	destroy_vector( &v, 0 );	
	
	vector vv;
	init_vector( &vv );
	
	for ( int i = 0; i < 256; ++i ) {	
		vector* k = malloc( sizeof(vector) );
		init_vector( k );
		
		for ( int j = 0; j < 256; ++j )
			push_vector( k, j );
			
		push_vector( &vv, k );
	}
	
	for ( int i = 0; i < 256; ++i )
		destroy_vector( get_elem_vector( &vv, i ), 0 );	
	
	destroy_vector( &vv, 1 );	
}

void vector_teststruct_p() {
	vector v;
	init_vector( &v );
	
	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_vector( &v, x );
	}

	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = get_elem_vector( &v, i );
		printf("%d, %c, %f ---", x -> k, x -> c, x -> g);
	}
	
	destroy_vector( &v, 1 );
	
	printf("\n");
}

void vector_testint_p() {
	vector v;
	init_vector( &v );

	for ( int i = 0; i < 128; ++i ) 
		push_vector( &v, i );

	for ( int i = 0; i < 128; ++i ) 
		printf( "%d ", get_elem_vector(&v, i) );

	for ( int i = 0; i < 128; ++i ) {
		int k = get_elem_vector( &v, i );
		k *= i >> 1;
		set_elem_vector( &v, i, k, 0 );
		printf( "%d ", get_elem_vector(&v, i) );	
	}
	
	printf("\n");
	
	for ( int i = 0; i < 128; ++i ) 
		insert_at_vector( &v, 0, 1 );
		
	for ( int i = 0; i < 256; ++i ) 	
		printf( "%d ", get_elem_vector( &v, i ) );		
		
	destroy_vector( &v, 0 );	
	
	printf("\n");
	
	vector vv;
	init_vector( &vv );
	
	for ( int i = 0; i < 16; ++i ) {	
		vector* k = malloc( sizeof(vector) );
		init_vector( k );
		
		for ( int j = 0; j < 16; ++j )
			push_vector( k, j );
			
		push_vector( &vv, k );
	}
	
	for ( int i = 0; i < 16; ++i ) {	
		for ( int j = 0; j < 16; ++j )
			printf("%d ", get_elem_vector(get_elem_vector(&vv, i), j) );
	}
	
	destroy_vector( &vv, 1 );
	printf("\n");	
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void queue_teststruct() {
	queue q;
	init_queue( &q );

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* x = malloc( sizeof(struct tester) );
			x -> k = i;
			x -> c = i % 26 + 'a';
			x -> g = i * i / 3.0;
			push_queue( &q, x );
		}
	
		for ( int i = 0; i < 4096; ++i ) 
			pop_queue( &q, 1 );
	}
	
	destroy_queue( &q, 0 );
}

void queue_testint() {
	queue q;
	init_queue( &q );
	
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			push_queue( &q, i );
	
		for ( int i = 0; i < 16384; ++i ) 
			pop_queue( &q, 0 );
			
		for ( int i = 0; i < 40000; ++i ) 
			push_queue( &q, i );
			
		for ( int i = 0; i < 20000; ++i ) 
			pop_queue( &q, 0 );
			
		for ( int i = 0; i < 20000; ++i ) 
			push_queue( &q, i );
			
		for ( int i = 0; i < 40000; ++i ) 
			pop_queue( &q, 0 );
	}
	
	destroy_queue( &q, 0 );
}


void queue_teststruct_p() {
	queue q;
	init_queue( &q );
	
	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_queue( &q, x );
	}

	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = front_queue( &q );
		printf("%d, %c, %f ---", x -> k, x -> c, x -> g);
		pop_queue( &q, 1 );
	}
	
	printf("\n");
	
	destroy_queue( &q, 0 );
}

void queue_testint_p() {
	queue q;
	init_queue( &q );

	for ( int i = 0; i < 128; ++i ) 
		push_queue( &q, i );
		
	printf("%d ", get_size_queue(&q) );

	for ( int i = 0; i < 128; ++i ) {
		printf("%d - %d ", front_queue(&q), back_queue(&q) );
		pop_queue( &q, 0 );
	}
	
	printf("\n");
	
	destroy_queue( &q, 0 );
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void deque_teststruct() {
	deque d;
	init_deque( &d );

	int t = 2;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			struct tester* x = malloc( sizeof(struct tester) );
			x -> k = i;
			x -> c = i % 26 + 'a';
			x -> g = i * i / 3.0;
			push_back_deque( &d, x );
		}
		
		for ( int i = 4096; i < 8192; ++i ) {
			struct tester* x = malloc( sizeof(struct tester) );
			x -> k = i;
			x -> c = i % 26 + 'a';
			x -> g = i * i / 3.0;
			push_front_deque( &d, x );
		}
	
		for ( int i = 0; i < 4096; ++i ) 
			pop_front_deque( &d, 1 );
			
		for ( int i = 0; i < 4096; ++i ) 
			pop_back_deque( &d, 1 );
	}
	
	destroy_deque( &d, 0 );
}

void deque_testint() {
	deque d;
	init_deque( &d );
	
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			push_front_deque( &d, i );
	
		for ( int i = 0; i < 16384; ++i ) 
			pop_back_deque( &d, 0 );
			
		for ( int i = 0; i < 40000; ++i ) 
			push_back_deque( &d, i );
			
		for ( int i = 0; i < 20000; ++i ) 
			pop_front_deque( &d, 0 );
			
		for ( int i = 0; i < 20000; ++i ) 
			push_back_deque( &d, i );
			
		for ( int i = 0; i < 40000; ++i ) 
			pop_back_deque( &d, 0 );
	}
	
	destroy_deque( &d, 0 );
}


void deque_teststruct_p() {
	deque d;
	init_deque( &d );
	
	for ( int i = 0; i < 32; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_back_deque( &d, x );
	}
	
	for ( int i = 32; i < 64; ++i ) {
		struct tester* x = malloc( sizeof(struct tester) );
		x -> k = i;
		x -> c = i % 26 + 'a';
		x -> g = i * i / 3.0;
		push_front_deque( &d, x );
	}

	for ( int i = 0; i < 64; ++i ) {
		struct tester* x = front_deque( &d );
		printf("%d, %c, %f ---", x -> k, x -> c, x -> g);
		struct tester* y = back_deque( &d );
		printf("%d, %c, %f ---", y -> k, y -> c, y -> g);
		
		if ( i % 2 )
			pop_back_deque( &d, 1 );
		else pop_front_deque( &d, 1 );
	}
	
	destroy_deque( &d, 0 );
	
	printf("\n");
}

void deque_testint_p() {
	deque d;
	init_deque( &d );

	for ( int i = 0; i < 128; ++i ) 
		push_back_deque( &d, i );
		
	printf("%d ", get_size_deque(&d));	

	for ( int i = 0; i < 128; ++i ) {
		printf("%d - %d ", front_deque(&d), back_deque(&d));
		
		if ( i % 2 == 0 )
			pop_back_deque( &d, 0 );
		else pop_front_deque( &d, 0 );
	}
	
	printf("\n");
	
	destroy_deque( &d, 0 );
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
		if ( !k ) {
			vector_testint();
			vector_teststruct();
		}
		else {
			vector_testint_p();
			vector_teststruct_p();
		}
	}
	else if ( strcmp(arg, "queue") == 0 ) {
		if ( !k ) {
			queue_testint();
			queue_teststruct();
		}
		else {
			queue_testint_p();
			queue_teststruct_p();
		}
	}
	else if ( strcmp(arg, "pqueue") == 0 ) {
		
	}
	else if ( strcmp(arg, "deque") == 0 ) {
		if ( !k ) {
			deque_testint();
			deque_teststruct();
		}
		else {
			deque_testint_p();
			deque_teststruct_p();
		}
	}
	else if ( strcmp(arg, "hash") == 0 ) {
		
	}
	else {
		/*	nothing  */
	}
	
	return 0;
}
