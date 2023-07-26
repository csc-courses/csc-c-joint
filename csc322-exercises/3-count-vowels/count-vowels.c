#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>

/*
 * count-vowels.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
 
 int count_vowels(char * s) {
 	char * vowels = "aeiou" ;
 	int i, n , count ;
 	n = strlen(s) ;
 	for (i=0; i<n; i++) {
 		if (strchr(vowels, s[i])) count++ ;	
 	}
 	return count ;
 } 
 
 int main(int argc, char * argv[]) {
 	int count ;
 	assert(argc==2) ;
 	printf("the number of vowels in |%s| is %d\n", argv[1], count_vowels(argv[1])) ;
 	return 0 ;
 }