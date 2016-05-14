#
# 	Makefile for all the data structures
#

CC = gcc
CFLAGS = -g -std=c99

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
all: test stl timer

# all stl commands
stl: stl_test.cpp
	g++ -std=c++11 -g stl_test.cpp -o stl_test

# gets time and memory usage of the function	
timer: time_val_test.c
	$(CC) $(CFLAGS) time_val_test.c -o time_val_test

# tester
test: $(OBJS_TMP) $(HEAD) test.c
	$(CC) $(CFLAGS) test.c -o test $(OBJS)

# magic
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(LOC)/$@

# clean up
clean: 
	$(RM) $(LOC)*.o test stl_test time_val_test
