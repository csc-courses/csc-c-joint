

F= pirate-boarding
G= pirate-print

all:
	@echo "targets are |make test-$F| or |make test-$G|"

$F: $F.c
	cc -o $@ $<
	
$G: $G.c
	cc -o $@ $<
	
test-$F: $F
	./$F
	
test-$G: $G
	./$G
	
clean:
	-rm $F $G
	
