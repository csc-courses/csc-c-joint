#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>
#include <ctype.h>

/*
 * my-atoi.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
 
 int my_atoi(char * s) {
 	int number = 0 ;
 	int i, n, sign  = 1 ;
 	
 	if (s[0]=='-') sign = -1 ;
 	n = strlen(s) ;
 	for (i=0;i<n;i++) {
 		if (isdigit(s[i])) number = number*10 + (s[i]-'0') ;
 	}
 	return sign*number ;
 } 
 
 int main(int argc, char * argv[]) {
 	int i, sum = 0 ;
 	for (i=1;i<argc;i++)
 		sum += my_atoi(argv[i]) ;
 	printf("the sum of the input numbers is %d.\n", sum) ;
 	return 0 ;
 }