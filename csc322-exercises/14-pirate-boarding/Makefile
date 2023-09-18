

F= pirate-boarding
G= pirate-print

all:
	make test
	make clean

$F: $F.c
	cc -o $@ $<
	
$G: $G.c
	cc -o $@ $<
	
test: $F $G
	./$F
	./$G
	
clean:
	-rm $F $G
	
