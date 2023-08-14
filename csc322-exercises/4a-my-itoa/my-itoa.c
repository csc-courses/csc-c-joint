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

void intToBase10String (int d, char s [], int len ) {
	int sign = 1 ;
	int i = 0 ;
	int j, t ;
	 
	if (d<0) {
		sign = -1 ;
		d = -d ;
	}
	while (d) {
 		s[i++] = (d%10)+'0' ;
 		d = d/10 ;
 		assert(i<len) ;
 	}
 	if (i==0) {
 		s[i] = '0' ;
 		i = 1 ;
 	}
 	if (sign<0) s[i++] = '-' ;
 	for (j=0;j<i/2;j++) {
 		t = s[j] ;
 		s[j] = s[i-j-1] ;
 		s[i-j-1] = t ;
 	}
	s[i] = '\0' ;
	return ;
}


int main(int argc, char * argv[]) {
 	char buffer[BUFFER_SIZE] ;
 	int len ;
 	assert(argc==2) ;
 	/*
 	len = my_itoa(buffer, BUFFER_SIZE, atoi(argv[1])) ;
 	reverse_print(buffer, len) ;
 	*/
 	
 	intToBase10String(atoi(argv[1]),buffer, BUFFER_SIZE) ;
 	printf("%s\n", buffer) ;
 	
 	return 0 ;
 }