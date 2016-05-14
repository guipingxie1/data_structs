#!/bin/bash

# Script to time implementations against stl
# Change permissions: chmod +x bash_script_name


# exit if anything fails
set -e

mkdir -p stackll
mkdir -p stack
mkdir -p stl_stack


# make so we have the newest version
make

# read in the data structure we want to test
# 
# stack, queue, vector, pqueue, deque, map, set, hash, all
#
echo ''
echo 'Input the data structure you want to test'
read data_struct

# don't exit if any of the testers fail
set +e

# newline for clarity
echo ''

if [ "$data_struct" == "stack" ] || [ "$data_struct" == "all" ] 
then
	echo Time of stack --- linked list implementation
	./bench ./test stackll stackll/stackll.txt

	echo Time of stack --- array implementation
	./bench ./test stack stack/stack.txt

	echo Time of std::stack --- c++ library
	./bench ./stl_test stack stl_stack/stack.txt

	diff -r stackll/stackll.txt stl_stack/stack.txt
	diff -r stack/stack.txt stl_stack/stack.txt

	echo Test of stack completed!

	rm -r stackll
	rm -r stack
	rm -r stl_stack
	echo ''
fi
	
if [ "$data_struct" == "vector" ] || [ "$data_struct" == "all" ]
then
	echo Time of vector
fi	
