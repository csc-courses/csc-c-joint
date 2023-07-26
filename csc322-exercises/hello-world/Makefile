#
# makefile for csc322
# last-update:
#	26 jul 2023
#

RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

all:
	make test
	make clean
	
hello-world: hello-world.c
	cc -o hello-world hello-world.c

test: hello-world
	./hello-world > hello.out
	echo "hello world!" > hello.ref
	diff hello.out hello.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm hello-world hello.out hello.ref
	

	
