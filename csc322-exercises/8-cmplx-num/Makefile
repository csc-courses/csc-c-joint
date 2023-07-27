#
# makefile for complex numbers
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= cmplx-num
G= cmplx-util

all:
	make test
	make clean

$F: $F.c $G.o $G.h
	cc -o $@ $G.o $<

$G.o: $G.c $G.h
	cc -c $<

test: $F
	echo "1.0 0.0\n 1.0 0.0" | ./$F > test.out
	echo "" >> test.out
	echo "0.0 1.0\n 0.0 1.0" | ./$F >> test.out
	echo "" >> test.out
	echo "1.0 1.0\n 1.0 -1.0" | ./$F >> test.out
	echo "" >> test.out
	echo "0.0 4.0\n -3.0 0.0" | ./$F >> test.out
	echo "" >> test.out
	cat test.out
	diff test.out test.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $G.o test.out

