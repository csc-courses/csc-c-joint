#
# makefile for linked-list
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= linked-list
G= ll-utils

all:
	make test
	make clean

linked-list: linked-list.c ll-utils.o linked-list.h
	cc -o $@ ll-utils.o $<

ll-utils.o: ll-utils.c linked-list.h
	cc -c $<

test: $F
	./$F one fish two fish > $F.out
	cat $F.out
	diff $F.out $F.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $G.o $F.out

