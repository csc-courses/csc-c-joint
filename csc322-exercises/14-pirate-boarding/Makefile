

F= pirate-boarding

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<
	
test: $F
	./$F
	
clean:
	-rm $F
	