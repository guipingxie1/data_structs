#
# 	Makefile for all the data structures
#

CC = gcc
CFLAGS = -g -std=c99

# all the source files
SRCS = stack_ll.c stack.c queue.c priority_queue.c set.c map.c vector.c deque.c hashtable.c

# all the object files
OBJS = $(SRCS:.c=.o)

# all the dependencies (headers)
HEAD = $(SRCS:.c=.h)


# everything
all: test

# tester
test: $(OBJS) $(HEAD) test.c
	$(CC) $(CFLAGS) test.c -o test $(OBJS)

# magic
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# clean up
clean: 
	$(RM) *.o test
