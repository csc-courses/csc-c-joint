#
# makefile for bcd routines
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= bcd-add

D= -D IS_SUB

all:
	make test
	make clean

$F: $F.c
	cc $D -o $@ $<

test: $F
	./$F 1 2    > test.out
	./$F 9 8    >> test.out
	./$F 13 10  >> test.out
	./$F 17  14 >> test.out
	./$F 30  20 >> test.out
	./$F 100 12 >> test.out
	./$F 123 87 >> test.out
	./$F 301 1  >> test.out
	./$F 001 1  >> test.out
	./$F 4 4    >> test.out
	diff test.out test.ref

	
clean:
	-rm $F test.out

