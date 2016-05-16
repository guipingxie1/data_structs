/**
 * 	@file: time_val_test.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Executable helper for testing implementation
 *	@date: Spring 2016
 *
 */

#define _GNU_SOURCE
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <sys/prctl.h>
#include <fcntl.h>



/**
 *	Signal handler for timeout
 *	Will exit the program after 10 seconds (real time)
 *
 *	@param signal: The signal we want to capture
 */
static void timeout(int signal) {
	printf( "  Time Limit Exceeded (10 seconds)\n\n" );
	exit( 1 );
}


/**
 *	Helper to wait for the child process
 *
 * 	@param pid: Process ID of the child (debuggee) 
 */
void wait_helper( pid_t pid ) {
	int status;
	int k = waitpid( pid, &status, 0 );			
	
	assert( (k != -1) && "Child process failed" ); 
}


/**
 *	Helper to redirect stderr and close the file descriptor
 *
 * 	@param ptr: A file pointer we will redirect stderr to
 */
void redirect_close_fd( FILE* ptr ) {
	int fd = fileno( ptr );
		
	/*	Make stderr go to file  */	
	assert( (dup2(fd, 2) != -1) && "Could not redirect stderr to our file" );

	assert( !close(fd) && "Could not close file descriptor" );
}


/**
 *	Helper for the child process
 *
 * 	@param ptr: A file pointer we will redirect stderr to
 * 	@param exec_arr: The array containing the program we want to execute
 */
void child_helper( FILE* ptr, const char** exec_arr ) {
	redirect_close_fd( ptr );

	int k = execvp( exec_arr[0], (char* const*)exec_arr );
	assert( (k != -1) && "Execution failed" );
}


/**
 *	Gets the program time and max memory usage 
 *	Uses rusage to time and get max memory
 *
 * 	@param pid: The pid of the execution child
 */
void benchmark( pid_t pid ) {
	/*	Structs we need for benchmarking  */
	struct timespec r_begin, r_end;
	struct rusage usage;
	struct timeval u_begin, u_end, s_begin, s_end;
	long mem_begin, mem_end;
	
	/*	Get the current usage details  */
	assert( (getrusage( RUSAGE_CHILDREN, &usage ) != -1) && "Cannot benchmark" );
	
	/*	User time  */
	u_begin = usage.ru_utime;
	
	/*	System time  */
	s_begin = usage.ru_stime;
	
	/*	Max memory usage  */
	mem_begin = usage.ru_maxrss;
	
	/*	Get the real (wall) clock time  */
	assert( (clock_gettime(CLOCK_MONOTONIC, &r_begin) != -1) && "Cannot time" );

	wait_helper( pid );
	
	/*	Get the child usage details (after waiting for it)  */
	assert( (getrusage( RUSAGE_CHILDREN, &usage ) != -1) && "Cannot benchmark" );
	u_end = usage.ru_utime;
	s_end = usage.ru_stime;
	
	assert( (clock_gettime(CLOCK_MONOTONIC, &r_end) != -1) && "Cannot time" );
	
	/*	Seconds  */
	double r_diff = r_end.tv_sec - r_begin.tv_sec;
	
	/*	Nanoseconds  */
	r_diff += (double)(r_end.tv_nsec - r_begin.tv_nsec) / 1000000000;
	
	double u_diff = u_end.tv_sec - u_begin.tv_sec;
	
	/*	Microseconds  */
	u_diff += (double)(u_end.tv_usec - u_begin.tv_usec) / 1000000;
	
	double s_diff = s_end.tv_sec - s_begin.tv_sec;
	s_diff += (double)(s_end.tv_usec - s_begin.tv_usec) / 1000000;

	printf( "  Real time (100 iterations in seconds): %f\n", r_diff );
	printf( "  User time (100 iterations in seconds): %f\n", u_diff );
	printf( "  System time (100 iterations in seconds): %f\n", s_diff );
	
	mem_end = usage.ru_maxrss;
	long max_mem = mem_end - mem_begin;
	printf( "  Maximum heap memory usage (in kilobytes): %ld\n", max_mem );
}


/**
 *	Runs the program 100 times and then benchmarks the child
 *	Calls benchmark to get the program time and max memory usage 
 *
 * 	@param args: Char array of function, data structure we are testing, output file 
 */
void time_function( char* args[] ) {
	pid_t timer = fork();
	assert( (timer != -1) && "Forking failed for time process" ); 
	
	/*	Child  */
	if ( !timer ) {
		char exec_cmd[ 4 + strlen(args[1]) + strlen(args[2]) ];
		strcpy( exec_cmd, args[1] );
		strcat( exec_cmd, " " );
		strcat( exec_cmd, args[2] );
		strcat( exec_cmd, " 0" );
		int k = -1;
		
		for ( int i = 0; i < 100; ++i ) {
			k = system( exec_cmd );
			assert( (k != -1) && "Execution for time failed" );
		}

		exit( 0 );
	}
	
	benchmark( timer );
}


/**
 *	Gets the program memory usage with valgrind
 *	Also calls time_function
 *	Outputs the time and then the memory usage
 *
 * 	@param args: Char array of function, data structure we are testing, output file 
 */
void get_valgrind( char* args[] ) {
	FILE* valgrind = tmpfile();
	assert( valgrind && "Temp file provided was NULL" ); 
	
	pid_t memory = fork();
	assert( (memory != -1) && "Forking failed for valgrind process" ); 
	
	/*	Child  */
	if ( !memory ) {
		const char* valgrind_args[6];
		valgrind_args[0] = "valgrind";
		valgrind_args[1] = "--tool=memcheck";
		valgrind_args[2] = args[1];
		valgrind_args[3] = args[2];
		valgrind_args[4] = "0";
		valgrind_args[5] = NULL;
		
		child_helper( valgrind, valgrind_args );
	}
	
	/*	Kill child if parent terminates  */
	prctl( PR_SET_PDEATHSIG, SIGHUP );		
	
	/*	Call time function in parent  */
	time_function( args );

	wait_helper( memory );
	
	/*	Move file pointer back to the beginning  */
	rewind( valgrind );
	char* line = NULL;
	size_t n = 0;
	char* mem;
	while ( getline(&line, &n, valgrind) != -1 ) {
		if ( (mem = strstr(line, "total heap usage:")) != NULL ) {
			printf( "  Total Memory Usage (valgrind):\n" );
			printf( "    %s\n", mem + 18 );
			break;
		}
	}

	free( line );
	fclose( valgrind );
}


/**
 *	Gets the output of the program and stores it in the provided file name
 *
 * 	@param args: Char array of function, data structure we are testing, output file 
 * 	@return The list of demangled function names
 */
void get_file( char* args[] ) {	
	pid_t parent_file = fork();
	assert( (parent_file != -1) && "Forking failed for valgrind process" ); 
	
	/*	Child  */
	if ( !parent_file ) {
		int fd = open( args[3], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR );
		dup2( fd, 1 );   
		close( fd );     
		
		const char* file_args[4];
		file_args[0] = args[1];
		file_args[1] = args[2];
		file_args[2] = "1";
		file_args[3] = NULL;
		
		int k = execvp( file_args[0], (char* const*)file_args );
		assert( (k != -1) && "Execution failed" );
	}
	
	wait_helper( parent_file );
}


/**
 *	Runs time, valgrind, and comparer benchmarks on the implementations
 *		argv: function_name data_struct_test output_file
 *
 * 	@param argc: The number of arguments (require 3)
 * 	@param argv: The char array of arguments
 */
int main( int argc, char* argv[] ) {
	assert( argc == 4 );
	
	/*	Kill child if parent terminates  */
	prctl( PR_SET_PDEATHSIG, SIGHUP );	

	/*  Structs needed to capture signal  */
	struct sigaction sa;
	sa.sa_handler = timeout;
	
	/*	Set sigaction signal handler  */
	assert( (sigaction(SIGALRM, &sa, NULL) != -1) && "Cannot set signal handler" );
	
	/**
	 *	Start a timer that expires after 10 seconds --- sends SIGALRM  
	 *	Will use this to handle long running programs
	 */
	alarm( 10 );			
	
	get_valgrind( argv );
	get_file( argv );	
	
	return 0;
}
