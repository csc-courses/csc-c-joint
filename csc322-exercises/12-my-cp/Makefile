#
# makefile for my-cp
# author:
# last-update: 
#    267 jul 2023 - template
#

RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= my-cp
COUNT= 1001

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<

test: $F
	dd if=/dev/urandom of=test.bin bs=1 count=${COUNT}
	wc -c test.bin
	hexdump test.bin | head -16
	./$F test.bin test.out
	cmp test.bin test.out
	./$F -a test.bin test.out
	cat test.bin test.bin > test-test.bin
	wc -c test-test.bin
	cmp test-test.bin test.out
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F test.bin test-test.bin test.out

