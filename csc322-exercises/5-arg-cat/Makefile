#
# makefile for arg-cat
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= arg-cat

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<

test: $F
	echo "hello world!" > $F.ref
	./$F  "!" d l r o w " " o l l e h  > $F.out
	diff $F.out $F.ref
	./$F  "!" "world" " " "hello"  > $F.out
	diff $F.out $F.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $F.out $F.ref

