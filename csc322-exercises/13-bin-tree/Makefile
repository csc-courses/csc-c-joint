#
# makefile for binary tree
# author:
# last-update: 
#    27 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= bin-tree
G= tree-utils

all:
	make test
	make clean

$F: $F.c $G.o $G.h
	cc -o $@ $G.o $<

$G.o: $G.c $G.h
	cc -c $<

R= "report food mother far board direction plate happy tide saw free thirty"

test: $F
	echo $R  ">" | ./$F
	echo $R "^" | ./$F > test.out
	diff test.out test.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $G.o test.out

