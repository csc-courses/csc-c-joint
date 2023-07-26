#
# makefile for my-atoi
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= hexout

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<

test: $F
	cat $F.in | ./$F > $F.out
	diff $F.out $F.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $F.out

