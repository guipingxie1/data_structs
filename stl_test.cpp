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

struct tester {
	int k;
	char c;
	double g;
};

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void stack_teststruct() {
	stack<tester> s;

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			tester x;
			x.k = i;
			x.c = i % 26 + 'a';
			x.g = i * i / 3.0;
			s.push( x );
		}
	
		for ( int i = 0; i < 4096; ++i ) 
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
			
		for ( int i = 0; i < 40000; ++i ) 
			s.push( i );
			
		for ( int i = 0; i < 20000; ++i ) 
			s.pop();
			
		for ( int i = 0; i < 20000; ++i ) 
			s.push( i );
			
		for ( int i = 0; i < 40000; ++i ) 
			s.pop();	
	}
}


void stack_teststruct_p() {
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

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void vector_teststruct() {
	vector<tester> v;

	int t = 4;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			tester x;
			x.k = i;
			x.c = i % 26 + 'a';
			x.g = i * i / 3.0;
			v.push_back( x );
		}
	
		for ( int i = 0; i < 4096; ++i ) 
			v[i].k = i << 1;
	}
	
	vector<tester> vv;
	
	for ( int i = 0; i < 512; ++i ) {
		tester x;
		x.k = i;
		x.c = i % 26 + 'a';
		x.g = i * i / 3.0;
		v.push_back( x );
	}
	
	v.resize(0);
}

void vector_testint() {
	vector<int> v;
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) 
			v.push_back( i );
	
		for ( int i = 0; i < 4096; ++i ) 
			v[i] *= (i >> 1);
			
		for ( int i = 0; i < 4096; ++i ) 
			v.erase(--v.end());
			
		for ( int i = 0; i < 16000; ++i ) 
			v.push_back( i );
			
		for ( int i = 0; i < 16000; ++i ) 
			v[i] = 0;	
			
		for ( int i = 0; i < 32; ++i )
			v.insert(v.begin(), 1);
			
		for ( int i = 0; i < 32; ++i )
			v.erase(v.begin());
			
		v.clear();			
	}	
	
	vector< vector<int> > vv;
	
	for ( int i = 0; i < 256; ++i ) {
		vector<int> k;
		
		for ( int j = 0; j < 256; ++j )
			k.push_back(j);
			
		vv.push_back(k);	
	}
}


void vector_teststruct_p() {
	vector<tester> v;
	
	for ( int i = 0; i < 64; ++i ) {
		tester x;
		x.k = i;
		x.c = i % 26 + 'a';
		x.g = i * i / 3.0;
		v.push_back( x );
	}

	for ( int i = 0; i < 64; ++i ) {
		tester x = v[i];
		printf("%d, %c, %f ---", x.k, x.c, x.g);
	}
	
	printf("\n");
}

void vector_testint_p() {
	vector<int> v;

	for ( int i = 0; i < 128; ++i ) 
		v.push_back( i );

	for ( int i = 0; i < 128; ++i ) 
		printf("%d ", v[i]);
		
	for ( int i = 0; i < 128; ++i ) {
		v[i] *= (i >> 1);
		printf("%d ", v[i]);	
	}
	
	printf("\n");
	
	for ( int i = 0; i < 128; ++i ) 
		v.insert(v.begin(), 1);
		
	for ( int i = 0; i < 256; ++i ) 	
		printf("%d ", v[i]);	
	
	printf("\n");
	
	vector< vector<int> > vv;
	
	for ( int i = 0; i < 16; ++i ) {
		vector<int> k;
		
		for ( int j = 0; j < 16; ++j )
			k.push_back(j);
			
		vv.push_back(k);	
	}

	for ( int i = 0; i < 16; ++i ) {
		for ( int j = 0; j < 16; ++j )
			printf("%d ", vv[i][j]);	
	}
	
	printf("\n");
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void queue_teststruct() {
	queue<tester> q;

	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			tester x;
			x.k = i;
			x.c = i % 26 + 'a';
			x.g = i * i / 3.0;
			q.push( x );
		}
	
		for ( int i = 0; i < 4096; ++i ) 
			q.pop();
	}
}

void queue_testint() {
	queue<int> q;
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			q.push( i );
	
		for ( int i = 0; i < 16384; ++i ) 
			q.pop();
			
		for ( int i = 0; i < 40000; ++i ) 
			q.push( i );
			
		for ( int i = 0; i < 20000; ++i ) 
			q.pop();
			
		for ( int i = 0; i < 20000; ++i ) 
			q.push( i );
			
		for ( int i = 0; i < 40000; ++i ) 
			q.pop();	
	}
}


void queue_teststruct_p() {
	queue<tester> q;
	
	for ( int i = 0; i < 64; ++i ) {
		tester x;
		x.k = i;
		x.c = i % 26 + 'a';
		x.g = i * i / 3.0;
		q.push( x );
	}

	for ( int i = 0; i < 64; ++i ) {
		tester x = q.front();
		printf("%d, %c, %f ---", x.k, x.c, x.g);
		q.pop();
	}
	
	printf("\n");
}

void queue_testint_p() {
	queue<int> q;

	for ( int i = 0; i < 128; ++i ) 
		q.push( i );
		
	printf("%d ", q.size());	

	for ( int i = 0; i < 128; ++i ) {
		printf("%d - %d ", q.front(), q.back());
		q.pop();
	}
	
	printf("\n");
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

void deque_teststruct() {
	deque<tester> d;

	int t = 2;
	
	while ( t-- ) {	
		for ( int i = 0; i < 4096; ++i ) {
			tester x;
			x.k = i;
			x.c = i % 26 + 'a';
			x.g = i * i / 3.0;
			d.push_back( x );
		}
		
		for ( int i = 4096; i < 8192; ++i ) {
			tester x;
			x.k = i;
			x.c = i % 26 + 'a';
			x.g = i * i / 3.0;
			d.push_front( x );
		}
	
		for ( int i = 0; i < 4096; ++i ) 
			d.pop_front();
			
		for ( int i = 0; i < 4096; ++i ) 
			d.pop_back();	
	}
}

void deque_testint() {
	deque<int> d;
	int t = 5;
	
	while ( t-- ) {	
		for ( int i = 0; i < 16384; ++i ) 
			d.push_front( i );
	
		for ( int i = 0; i < 16384; ++i ) 
			d.pop_back();
			
		for ( int i = 0; i < 40000; ++i ) 
			d.push_back( i );
			
		for ( int i = 0; i < 20000; ++i ) 
			d.pop_front();
			
		for ( int i = 0; i < 20000; ++i ) 
			d.push_back( i );
			
		for ( int i = 0; i < 40000; ++i ) 
			d.pop_back();	
	}
}


void deque_teststruct_p() {
	deque<tester> d;
	
	for ( int i = 0; i < 32; ++i ) {
		tester x;
		x.k = i;
		x.c = i % 26 + 'a';
		x.g = i * i / 3.0;
		d.push_back( x );
	}
	
	for ( int i = 32; i < 64; ++i ) {
		tester x;
		x.k = i;
		x.c = i % 26 + 'a';
		x.g = i * i / 3.0;
		d.push_front( x );
	}

	for ( int i = 0; i < 64; ++i ) {
		tester x = d.front();
		printf("%d, %c, %f ---", x.k, x.c, x.g);
		tester y = d.back();
		printf("%d, %c, %f ---", y.k, y.c, y.g);
		
		if ( i % 2 )
			d.pop_back();
		else d.pop_front();
	}
	
	printf("\n");
}

void deque_testint_p() {
	deque<int> d;

	for ( int i = 0; i < 128; ++i ) 
		d.push_back( i );
		
	printf("%d ", d.size());	

	for ( int i = 0; i < 128; ++i ) {
		printf("%d - %d ", d.front(), d.back());
		
		if ( i % 2 == 0 )
			d.pop_back();
		else d.pop_front();
	}
	
	printf("\n");
}

//-------------------------------------------------------------------

//-------------------------------------------------------------------

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
		if ( !k ) {
			vector_testint();
			vector_teststruct();
		}
		else {
			vector_testint_p();
			vector_teststruct_p();
		}
	}
	else if ( arg.compare("queue") == 0 ) {
		if ( !k ) {
			queue_testint();
			queue_teststruct();
		}
		else {
			queue_testint_p();
			queue_teststruct_p();
		}
	}
	else if ( arg.compare("pqueue") == 0 ) {
		
	}
	else if ( arg.compare("deque") == 0 ) {
		if ( !k ) {
			deque_testint();
			deque_teststruct();
		}
		else {
			deque_testint_p();
			deque_teststruct_p();
		}
	}
	else if ( arg.compare("hash") == 0 ) {
		
	}
	else {
		/*	nothing  */
	}
}
