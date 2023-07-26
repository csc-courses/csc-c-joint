#
# makefile for my-atoi
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= my-atoi

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<

test: $F
	./$F 1 2 -3 > $F.out
	./$F 0 19 -7 -2 4 >> $F.out
	./$F -1 -1 -2 3 >> $F.out
	diff $F.out $F.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $F.out

