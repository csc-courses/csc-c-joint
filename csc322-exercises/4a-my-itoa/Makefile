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

all:
	make test
	make clean

my-itoa: my-itoa.c
	cc -o my-itoa my-itoa.c

test: my-itoa
	./my-itoa 0
	./my-itoa 1
	./my-itoa 21
	./my-itoa 321
	./my-itoa 4321
	./my-itoa 12345
	./my-itoa -0
	./my-itoa -1
	./my-itoa -21
	./my-itoa -321
	./my-itoa -4321
	./my-itoa -12345
	
clean:
	-rm my-itoa


