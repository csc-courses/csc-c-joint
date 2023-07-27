#
# makefile for complex vectors
# author:
# last-update: 
#    26 jul 2023 - template
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m

F= cmplx-vec
G= cmplx-util

all:
	make test
	make clean

cmplx-vec: cmplx-vec.c cmplx-util.o cmplx-util.h
	cc -o $@ cmplx-util.o $<

cmplx-util.o: cmplx-util.c cmplx-util.h
	cc -c $<

V1= "1.0 0.0 1.0 0.0 1.0 0.0"
V2= "1.0 1.0 -1.0 0.0 0.0 -1.0"
test: $F
	echo ${V1} "\n" ${V1} | ./$F > $F.out
	echo "" >> $F.out
	echo ${V1} "\n" ${V2} | ./$F >> $F.out
	echo "" >> $F.out
	echo ${V2} "\n" ${V2} | ./$F >> $F.out
	cat $F.out
	diff $F.out $F.ref
	@echo "*** ${GREEN}PASSED ${NC}***"
	
clean:
	-rm $F $G.o $F.out

