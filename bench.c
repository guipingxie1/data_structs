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
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <fcntl.h>


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
		
	// make stdout go to file	
	assert( (dup2(fd, 2) != -1) && "Could not redirect stderr to our file" );
	
	// fd no longer needed - the dup'ed handles are sufficient
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
 *	Gets the program memory usage with valgrind
 *	Also calls time_function
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
		
		struct tms start_time, end_time;
		clock_t begin, end;
		begin = times( &start_time );
/*		
		struct timespec begin, end;
		clock_gettime(CLOCK_MONOTONIC, &begin);
		clock_t start_time = clock();
*/		
		for ( int i = 0; i < 100; ++i ) {
			k = system( exec_cmd );
			assert( (k != -1) && "Execution for time failed" );
		}
/*		
		clock_gettime(CLOCK_MONOTONIC, &end); 
		
		/*	Seconds  */
		//double diff = end.tv_sec - begin.tv_sec;
		
		/*	Nanoseconds  */
		//diff += (double)(end.tv_nsec - begin.tv_nsec) / 1000000000;
/*		
		printf( "  Wall time (100 iterations in seconds): %f\n", (double)diff );	
		
		clock_t end_time = clock();
		double cpu_time = (double)( end_time - start_time ) / CLOCKS_PER_SEC;
			
		printf( "  CPU time (100 iterations in seconds): %f\n", cpu_time );
*/		

		end = times( &end_time );
		
		printf( "  %f %f %f %f %f %f \n", end, begin, end_time.tms_utime, start_time.tms_utime, end_time.tms_stime, start_time.tms_stime );
		
		printf( "  Real time (100 iterations in seconds): %f\n", end - begin );
		printf( "  User time (100 iterations in seconds): %f\n", end_time.tms_utime - start_time.tms_utime );
		printf( "  System time (100 iterations in seconds): %f\n", end_time.tms_stime - start_time.tms_stime );
		
		exit( 0 );
	}

	wait_helper( timer );
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
			printf( "  %s\n", mem + 18 );
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
	
	get_valgrind( argv );
	get_file( argv );
	
	return 0;
}
