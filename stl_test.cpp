#include <stack>
#include <queue>				// contains both queue, priority queue
#include <deque>
#include <map>
#include <set>
#include <vector>

#include <string>
#include <cassert>


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
	
	for ( int i = 0; i < 65536; ++i ) 
		s.push( i );
}


int main( int argc, char* argv[] ) {
	assert( argc == 2 );
	
	string arg = argv[1];
	
	if ( arg.compare("stack") == 0 ) {
		stack_testint();
		stack_teststruct();
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
