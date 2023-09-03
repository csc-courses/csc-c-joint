#
# makefile for my-itoa
# author:
# last-update: 
#    14 aug 2023 - template
#

RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

NUMBER = 123

F= to-base-10-string

all:
	make test
	make clean

$F: $F.c
	cc -o $F $F.c

test: $F
	./$F 0
	./$F 1
	./$F 21
	./$F 321
	./$F 4321
	./$F 12345
	./$F -0
	./$F -1
	./$F -21
	./$F -321
	./$F -4321
	./$F -12345
	
clean:
	-rm $F


