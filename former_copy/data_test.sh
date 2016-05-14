#!/bin/bash

# Script to time implementations against stl
# Change permissions: chmod +x bash_script_name


# exit if anything fails
set -e

mkdir -p stackll
mkdir -p stack
mkdir -p stl_stack


make



# runs the test file 100 times
time_hundred_iter() {
	for i in {1..100}
	do 
		$1 $2 $3
	done	
}



# don't exit if any of the testers fail
set +e

# newline for clearity
echo ''

echo Time of stack_ll
time time_hundred_iter ./test stackll 0
./test stackll > stackll/stackll.txt 1
valgrind --tool=memcheck ./test stackll 0
echo ''

echo Time of stack-array
time time_hundred_iter ./test stack 0 
./test stack > stack/stack.txt 1
valgrind --tool=memcheck ./test stack 0
echo ''

echo Time of std::stack
time time_hundred_iter ./stl_test stack 0
./stl_test stack > stl_stack/stack.txt 1
valgrind --tool=memcheck ./stl_test stack 0
echo ''

diff -r stackll/stackll.txt stl_stack/stack.txt
diff -r stack/stack.txt stl_stack/stack.txt

echo Test completed!
