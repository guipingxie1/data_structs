#!/bin/bash

# Script to time implementations against stl
# Change permissions: chmod +x bash_script_name


# exit if anything fails
set -e

make
g++ -std=c++11 -g stl_test.cpp -o stl_test

# runs the test file 100 times
time_hundred_iter() {
	for i in {1..100}
	do 
		$1 $2
	done	
}



# don't exit if any of the testers fail
set +e

# newline for clearity
echo ''

echo Time for stack_ll
time time_hundred_iter ./test stackll
echo ''

echo Time for stack-array
time time_hundred_iter ./test stack
echo ''

echo Time for std::stack
time time_hundred_iter ./stl_test stack
echo ''

echo Test completed!
