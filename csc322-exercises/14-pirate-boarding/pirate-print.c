#include<stdio.h>
#include<stdlib.h>

char ** location ;

#define PIRATE_SECRET 44 

void pirate_print(void) {
	int marker ;
	char * ip = (char *) &marker ;
	//printf("%p %p\n", location, ip) ;
	//*location = "There be pirates!" ;
        *(ip+PIRATE_SECRET) = "There be pirates!" ;	
	return ;
}


void print_it(char * to_print) {
	location = &to_print ;	
	pirate_print() ;
	printf("%s\n", to_print) ;
	return ;
}


int main(int argc, char * argv[]) {
	print_it("Are there pirates?") ;
	return 0 ;
}
