#include<stdio.h>
#include <stdlib.h>
#include<assert.h>

/*
 * boom.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
 
 int main(int argc, char * argv[]) {
 	int i, n ;
 	assert(argc==2) ;
 	n = atoi(argv[1]) ;
 	assert(n>=0) ;
 	
 	for (i=0;i<n;i++) {
 		printf("%d ", n-i) ;
  	}
  	printf("BOOM!\n") ;
 	return 0 ;
 }