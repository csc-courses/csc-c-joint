#
# makefile for bcd routines
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= binary-float


all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<
	

test: $F
	./$F 24 5
	@echo ""
	./$F 24 25
	@echo ""
	./$F 24 2
	@echo ""
	./$F 24 7
	@echo ""
	./$F 24 001

clean:
	-rm $F

