#
# 	Makefile for all the data structures
#				also includes benchmark testing 
#

CC = gcc
CFLAGS = -g -std=c99 -w

# all the source files
SRCS = stack_ll.c stack.c queue.c priority_queue.c set.c map.c vector.c deque.c hashtable.c

# objects location
LOC = object_files

# all the object files
# moves the object files to a different folder so directory is not as cluttered
OBJS_TMP = $(SRCS:.c=.o)
OBJS = $(patsubst %.o, $(LOC)/%.o, $(OBJS_TMP))

# all the dependencies (headers)
HEAD = $(SRCS:.c=.h)


# everything
all: test stl_test bench

# all stl commands
stl_test: stl_test.cpp
	g++ -std=c++11 -g stl_test.cpp -o stl_test

# gets time and memory usage of the function	
bench: bench.c
	$(CC) $(CFLAGS) bench.c -o bench

# tester
test: $(OBJS) $(HEAD) test.c
	$(CC) $(CFLAGS) test.c -o test $(OBJS)

# magic
$(LOC)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up
clean: 
	$(RM) $(LOC)/*.o test stl_test bench
