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



# don't exit if any of the testers fail
set +e

# newline for clearity
echo ''

echo Time of stack_ll
./bench ./test stackll stackll/stackll.txt

echo Time of stack-array
./bench ./test stack stack/stack.txt

echo Time of std::stack
./bench ./stl_test stack stl_stack/stack.txt

diff -r stackll/stackll.txt stl_stack/stack.txt
diff -r stack/stack.txt stl_stack/stack.txt

echo Test completed!

rm -r stackll
rm -r stack
rm -r stl_stack
