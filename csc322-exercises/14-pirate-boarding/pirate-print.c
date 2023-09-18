#include<stdio.h>
#include<stdlib.h>


/*
 * long john von neumann hooks the stack
 * author: bjr
 * last-update:
 *    18 sep 2023
 *
 * NOTICE - THESE ARE PIRATE TECHINQUES! This code is most likely not portable
 * across operating systems or machine architectures.
 *
 */


// pirates also like globals

char ** location ;
int there_be_pirates = 0 ;

// you need to find the pirate secret!
//
#define PIRATE_SECRET 44 

void pirate_boarding(void) {
	int stack_marker ;
	char * ip = (char *) &stack_marker ;
        *(ip+PIRATE_SECRET) = "*** There be pirates! ***" ;	
	return ;
}

void print_it(char * string_pointer_on_stack) {
	location = &string_pointer_on_stack ;	
	if (there_be_pirates) {
		pirate_boarding() ;
	}
	printf("%s\n", string_pointer_on_stack) ;
	return ;
}

int main(int argc, char * argv[]) {
	printf("Are there pirates in these cyberwaters?\n") ;
	print_it("No, there are no pirates.\n" ) ;
	there_be_pirates = 1 ;
	printf("Are there pirates in these cyberwaters?\n") ;
	print_it("No, there are no pirates.\n" ) ;
	return 0 ;
}

