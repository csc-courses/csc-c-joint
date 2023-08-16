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

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<

test: $F
	./$F 1 2
	./$F 9 8
	./$F 10 13
	./$F 14  17
	./$F 20  30
	./$F 100 12
	./$F 123 87
	./$F 301 1
	./$F 001 1
	
	
clean:
	-rm $F $F.out

