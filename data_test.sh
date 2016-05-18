#!/bin/bash

# Script to Benchmark implementations against stl
# Requires folders stack, vector, 
#		Make sure those folders are not already made because it will be deleted 
#
# Change permissions: chmod +x bash_script_name


# exit if anything fails
set -e


# make so we have the newest version
make

# clear the terminal screen
clear
echo 'Cleared screen'

# read in the data structure we want to test
# 
# stack, queue, vector, pqueue, deque, map, set, hash, all
#
echo ''
echo 'Input the data structure you want to test'
echo '  stack, queue, vector, pqueue, deque, map, set, hash, or all (all test)'
read data_struct

# don't exit if any of the testers fail
set +e

# newline for clarity
echo ''

# stack test
if [ "$data_struct" == "stack" ] || [ "$data_struct" == "all" ] 
then
	mkdir -p stack

	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of stack --- linked list implementation
	./bench ./test stackll stack/stackll.txt

	echo Benchmark of stack --- array implementation
	./bench ./test stack stack/stack.txt

	echo Benchmark of std::stack --- c++ library
	./bench ./stl_test stack stack/stl_stack.txt

	diff stack/stackll.txt stack/stl_stack.txt
	diff stack/stack.txt stack/stl_stack.txt

	echo 'Test of stack completed!'
	echo ''
	
	rm -r stack
fi
	
# vector test	
if [ "$data_struct" == "vector" ] || [ "$data_struct" == "all" ]
then
	mkdir -p vector
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of vector --- array implementation
	./bench ./test vector vector/vector.txt
	
	echo Benchmark of std::vector --- c++ library
	./bench ./stl_test vector vector/stl_vector.txt
	
	diff vector/vector.txt vector/stl_vector.txt
	
	echo 'Test of vector completed!'
	echo ''
	
	rm -r vector
fi	

# queue test
if [ "$data_struct" == "queue" ] || [ "$data_struct" == "all" ]
then
	mkdir -p queue
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of queue --- 
	./bench ./test queue queue/queue.txt
	
	echo Benchmark of std::queue --- c++ library
	./bench ./stl_test queue queue/stl_queue.txt
	
	diff queue/queue.txt queue/stl_queue.txt
	
	echo 'Test of queue completed!'
	echo ''
	
	rm -r queue
fi	

# deque test
if [ "$data_struct" == "deque" ] || [ "$data_struct" == "all" ]
then
	mkdir -p deque
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of deque --- 
	./bench ./test deque deque/deque.txt
	
	echo Benchmark of std::deque --- c++ library
	./bench ./stl_test deque deque/stl_deque.txt
	
	diff deque/deque.txt deque/stl_deque.txt
	
	echo 'Test of deque completed!'
	echo ''
	
	rm -r deque
fi	

# pqueue test
if [ "$data_struct" == "pqueue" ] || [ "$data_struct" == "all" ]
then
	mkdir -p pqueue
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of pqueue --- 
	
	
	echo Benchmark of std::pqueue --- c++ library
	./bench ./stl_test pqueue pqueue/stl_pqueue.txt
	
	diff pqueue/pqueue.txt pqueue/stl_pqueue.txt
	
	echo 'Test of pqueue completed!'
	echo ''
	
	rm -r pqueue
fi

# map test
if [ "$data_struct" == "map" ] || [ "$data_struct" == "all" ]
then
	mkdir -p map
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of map --- 
	
	
	echo Benchmark of std::map --- c++ library
	./bench ./stl_test map map/stl_map.txt
	
	diff map/map.txt map/stl_map.txt
	
	echo 'Test of map completed!'
	echo ''
	
	rm -r map
fi

# set test
if [ "$data_struct" == "set" ] || [ "$data_struct" == "all" ]
then
	mkdir -p set
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of set --- 
	
	
	echo Benchmark of std::set --- c++ library
	./bench ./stl_test set set/stl_set.txt
	
	diff set/set.txt set/stl_set.txt
	
	echo 'Test of set completed!'
	echo ''
	
	rm -r set
fi

# hash test
if [ "$data_struct" == "hash" ] || [ "$data_struct" == "all" ]
then
	mkdir -p hash
	
	echo '-----------------------------------------------------------------------'
	echo ''
	
	echo Benchmark of hash --- 
	
	
	echo Benchmark of std::hash --- c++ library
	./bench ./stl_test hash hash/stl_hash.txt
	
	diff hash/hash.txt hash/stl_hash.txt
	
	echo 'Test of hash completed!'
	echo ''
	
	rm -r hash
fi
