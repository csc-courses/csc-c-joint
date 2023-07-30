#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
 * long john von neumann hooks the stack 
 * author: bjr
 * last-update:
 *    29 jul 2023
 *
 */
 

long int return_to ; 
long int there_be_pirates = 0 ;

#define PIRATE_SECRET 2 

void caribbean_voyage() {
	long int i ;  // a place on the stack, for the pirate's hook!
	printf("\nAre there pirates?\n" ) ;
	
	if (there_be_pirates) {
		// the pirate places the pirate ship on the return statck
		*(&i+PIRATE_SECRET) = return_to ;
	}
	return ;
}

void pirate_ship() {
	printf("*** You have been boarded by pirate Long John von Neumann! ***\n\n") ;
	exit(0) ;
}

int main(int argc, char * argv[]) {

	// pirate programming. it is often the case that a function
	// the address of its entry point, and that addresses are simply
	// long ints.
	
	// this allows our program to be boarded by the 
	// infamous pirate long john von neumann. 
	
	return_to = (long int) pirate_ship ;

	caribbean_voyage() ;
	printf("There were no pirates.\n") ;
	
	there_be_pirates = 1 ;
	caribbean_voyage() ;
	
	// never get here
	assert(0==1) ;
	return 0 ;
}