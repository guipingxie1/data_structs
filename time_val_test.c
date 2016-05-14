/**
 * 	@file: time_val_test.c
 * 	@author: Guiping Xie 
 *
 * 	@description: Executable helper for testing implementation
 *	@date: Spring 2016
 *
 */

#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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
 * 	@param funct_names: The function names
 * 	@return The list of demangled function names
 */
void time_function( char* args[] ) {
	pid_t time = fork();
	assert( (time != -1) && "Forking failed for time process" ); 
	
	/*	Child  */
	if ( !time ) {
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

	wait_helper( time );
}


/**
 *	Gets the program memory usage with valgrind
 *	Also calls time_function
 *	Outputs the time and then the memory usage
 *
 * 	@param funct_names: The function names
 * 	@return The list of demangled function names
 */
void get_valgrind( char* args[] ) {
	FILE* valgrind = tmpfile();
	assert( valgrind && "Temp file provided was NULL" ); 
	
	pid_t memory = fork();
	assert( (memory != -1) && "Forking failed for valgrind process" ); 
	
	/*	Child  */
	if ( !memory ) {
		const char* objdump_args[4];
		objdump_args[0] = "objdump";
		objdump_args[1]	= "--dwarf=decodedline";
		objdump_args[2]	= args[1];
		objdump_args[3] = NULL;
		
		child_helper( valgrind, objdump_args );
	}
	
	/*	Call time function in parent  */
	time_function( args );

	wait_helper( memory );
	
	rewind( valgrind );
	char* line = NULL;
	size_t n = 0;
	while ( getline(&line, &n, ptr) != -1 ) {
		
	}

	free( line );
	fclose( ptr );
}


/**
 *	Runs 
 *
 * 	@param argc: The number of arguments 
 * 	@param argv: The char array of arguments
 */
int main( int argc, char* argv[] ) {
	assert( argc == 3 );
	
	get_valgrind( argv );
	
	
	return 0;
}
