#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

/*
 * hexout.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

#define BUF_SIZE 1024
#define DEBUG 0

#ifndef IS_SUB
#define IS_SUB 0
#endif

uint32_t ato_bcd(char a[], int len) {
	int i, j = 0 ;
	uint32_t r = 0, d ;
	
	assert( len <= (2*sizeof(int)) ) ;

	for (i=len-1;i>=0;i--) {
		d = a[i]-'0' ;
		r += d<<j ;
		j += 4 ;
	}
	return r ;
}

int bcd_toa( uint32_t d, char a[], int len ) {
	int bit, i ;
	int l = 2*sizeof(int) ;
	
	if (!d) {
		a[0] = '0' ;
		return 1 ;	
	}
	
	for (bit = (8*sizeof(int))-4; bit>=0; bit-=4) {
		if ((d>>bit)) break ;
		l-- ;
	}

	for (i=0;i<l;i++) {
		a[l-i-1] = (0x0f&d)+'0' ;
		d = d>>4 ;
	}
	return l ;
}

int bcd_add_aux(uint32_t d1, uint32_t d2, int carry) {
	uint32_t d = 0 ;
	int i, t  ;
	for (i=0; i<2*sizeof(uint32_t); i++) {
	
		t = (0xf&d1)+(0xf&d2)+carry  ;
		if (t>9) {
			carry = 1 ;
			t -= 10 ;
		} else 
			carry = 0 ;

		d += t<<(4*i) ;
		d1 >>= 4 ;
		d2 >>= 4 ;
	}
	return d ;
}

uint32_t bcd_add(uint32_t d1, uint32_t d2) {
	return bcd_add_aux(d1, d2, 0 ) ;
}

uint32_t bcd_9complement(uint32_t d) {
	uint32_t d1 = 0 ;
	int i, t  ;
	for (i=0; i<2*sizeof(int); i++) {
		t = 9-(0xf&d) ;
		d1 += t<<(4*i) ;
		d >>= 4 ;
	}
	return d1 ;
}

uint32_t bcd_sub(uint32_t d1, uint32_t d2) {
	uint32_t d = bcd_9complement(d2) ;
	return bcd_add_aux(d1,d,1) ;
}

int main(int argc, char * argv[]) {
	uint32_t d1, d2, d_add, d_sub ;
	char s1[1*sizeof(int)+1] ;
	char s2[2*sizeof(int)+1] ;
	char s[2*sizeof(int)+1] ;
	int len ;

	char op = '+' ;

	assert(argc==3) ;
	assert(sizeof(uint32_t)==4) ;
	
	d1 = ato_bcd(argv[1], strlen(argv[1])) ;
	d2 = ato_bcd(argv[2], strlen(argv[2])) ;
	
	len = bcd_toa(d1, s1, 2*sizeof(uint32_t)) ;
	s1[len] = '\0' ;
	len = bcd_toa(d2, s2, 2*sizeof(uint32_t)) ;
	s2[len] = '\0' ;

	d_add = bcd_add(d1, d2) ;
	d_sub = bcd_sub(d1, d2) ;

	len = bcd_toa(d_add, s, 2*sizeof(uint32_t)) ;
	s[len] = '\0' ;
	printf("%s %c %s = %s\n", s1, '+', s2, s ) ;
	len = bcd_toa(d_sub, s, 2*sizeof(uint32_t)) ;
	s[len] = '\0' ;
	printf("%s %c %s = %s\n", s1, '-', s2, s ) ;
	
	
 	return 0 ;
 }