#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

/*
 * my-itoa.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
 #define BUFFER_SIZE 100
 
 int my_itoa(char s [], int n, int d ) {
 	int i = 0 ;
 	while (d) {
 		s[i++] = (d%10)+'0' ;
 		d = d/10 ;
 		assert(i<n) ;
 	}
 	if (i==0) {
 		s[i] = '0' ;
 		i = 1 ;
 	}
 	return i ;
 } 
 
void reverse_print(char s [], int len) {
	int i ;
	for (i=len-1;i>=0; i--) {
		printf("%c", s[i]) ;
	}
	printf("\n") ;
	return ;
}

int main(int argc, char * argv[]) {
 	char buffer[BUFFER_SIZE] ;
 	int len ;
 	assert(argc==2) ;
 	len = my_itoa(buffer, BUFFER_SIZE, atoi(argv[1])) ;
 	reverse_print(buffer, len) ;
 	return 0 ;
 }