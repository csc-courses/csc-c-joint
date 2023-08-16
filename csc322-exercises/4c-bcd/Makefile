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
G= bcd-sub

D= -D IS_SUB

all:
	make test
	make clean

$F: $F.c
	cc $D -o $@ $<

test: $F
	./$F 1 2
	./$F 9 8
	./$F 13 10
	./$F 17  14
	./$F 30  20
	./$F 100 12
	./$F 123 87
	./$F 301 1
	./$F 001 1
	./$F 4 4 


	
clean:
	-rm $F $F.out

