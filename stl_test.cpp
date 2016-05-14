/**
 * 	@file: stl_test.cpp
 * 	@author: Guiping Xie 
 *
 * 	@description: Tests the stl data structures
 *	@date: Spring 2016
 *
 */

#include <stack>
#include <queue>				// contains both queue, priority queue
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <unordered_set>		// hashtable

#include <string>
#include <cassert>
#include <cstdio>


using namespace std;


void stack_teststruct() {
	struct tester {
		int k;
		char c;
		double g;
	};

	stack<tester> s;

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) {
			tester x;
			x.k = i;
			x.c = i % 26 + 'a';
			x.g = i * i / 3.0;
			s.push( x );
		}
	
		for ( int i = 0; i < 16384; ++i ) 
			s.pop();
	}
}

void stack_testint() {
	stack<int> s;
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			s.push( i );
	
		for ( int i = 0; i < 16384; ++i ) 
			s.pop();
			
		for ( int i = 0; i < 65536; ++i ) 
			s.push( i );
			
		for ( int i = 0; i < 32768; ++i ) 
			s.pop();
			
		for ( int i = 0; i < 32768; ++i ) 
			s.push( i );
			
		for ( int i = 0; i < 65536; ++i ) 
			s.pop();	
	}
}


void stack_teststruct_p() {
	struct tester {
		int k;
		char c;
		double g;
	};

	stack<tester> s;
	
	for ( int i = 0; i < 64; ++i ) {
		tester x;
		x.k = i;
		x.c = i % 26 + 'a';
		x.g = i * i / 3.0;
		s.push( x );
	}

	for ( int i = 0; i < 64; ++i ) {
		tester x = s.top();
		printf("%d, %c, %f ---", x.k, x.c, x.g);
		s.pop();
	}
	
	printf("\n");
}

void stack_testint_p() {
	stack<int> s;

	for ( int i = 0; i < 128; ++i ) 
		s.push( i );

	for ( int i = 0; i < 128; ++i ) {
		int k = s.top();
		printf("%d ", k);
		s.pop();
	}
	
	printf("\n");
}


int main( int argc, char* argv[] ) {
	assert( argc == 3 );
	
	string arg = argv[1];
	int k = atoi( argv[2] );			// 1 if we want to print
	
	if ( arg.compare("stack") == 0 ) {
		if ( !k ) {
			stack_testint();
			stack_teststruct();
		}
		else {
			stack_testint_p();
			stack_teststruct_p();
		}
	}
	else if ( arg.compare("set") == 0 ) {
		
	}
	else if ( arg.compare("map") == 0 ) {
		
	}
	else if ( arg.compare("vector") == 0 ) {
		
	}
	else if ( arg.compare("queue") == 0 ) {
		
	}
	else if ( arg.compare("pqueue") == 0 ) {
		
	}
	else if ( arg.compare("deque") == 0 ) {
		
	}
	else if ( arg.compare("hash") == 0 ) {
		
	}
	else {
		/*	nothing  */
	}
}
