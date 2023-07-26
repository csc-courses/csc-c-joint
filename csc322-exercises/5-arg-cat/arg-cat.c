#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>
#include <ctype.h>

/*
 * arg-reverse.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
 int main(int argc, char * argv[]) {
 	int i, n = 0 ;
 	char * s ;
 	for (i=1;i<argc;i++)
 		n += strlen(argv[i]) ;
 	s = (char *) malloc(n+1) ;
 	s[0] = '\0' ;
 	for (i=1;i<argc;i++)
 		s = strcat(s,argv[argc-i]) ;
 	printf("%s\n", s) ;
 	free(s) ;
 	return 0 ;
 }