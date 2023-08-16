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

int ato_bcd(char a[], int len) {
	int i, j = 0 ;
	int r = 0, d ;
	
	assert( len <= (2*sizeof(int)) ) ;

	for (i=len-1;i>=0;i--) {
		d = a[i]-'0' ;
		r += d<<j ;
		j += 4 ;
	}
	return r ;
}

int bcd_toa( int d, char a[], int len ) {
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

int bcd_add_aux(int d1, int d2, int carry) {
	int d = 0, t ;
	int i  ;
	for (i=0; i<2*sizeof(int); i++) {
	
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

int bcd_add(int d1, int d2) {
	return bcd_add_aux(d1, d2, 0 ) ;
}

int bcd_9complement(int d) {
	int d1 = 0, t ;
	int i  ;
	for (i=0; i<2*sizeof(int); i++) {
		t = 9-(0xf&d) ;
		d1 += t<<(4*i) ;
		d >>= 4 ;
	}
	return d1 ;
}

int bcd_sub(int d1, int d2) {
	int d = bcd_9complement(d2) ;
	return bcd_add_aux(d1,d,1) ;
}

int main(int argc, char * argv[]) {
	int d1, d2, d ;
	char s1[1*sizeof(int)+1] ;
	char s2[2*sizeof(int)+1] ;
	char s[2*sizeof(int)+1] ;
	int len ;
	assert(argc==3) ;
	char op = '+' ;

	d1 = ato_bcd(argv[1], strlen(argv[1])) ;
	d2 = ato_bcd(argv[2], strlen(argv[2])) ;
	
	len = bcd_toa(d1, s1, 2*sizeof(int)) ;
	s1[len] = '\0' ;
	len = bcd_toa(d2, s2, 2*sizeof(int)) ;
	s2[len] = '\0' ;

#ifndef IS_SUB
	d = bcd_add(d1, d2) ;
#else
	d = bcd_sub(d1, d2) ;
	op = '-' ;
#endif

	len = bcd_toa(d, s, 2*sizeof(int)) ;
	s[len] = '\0' ;
	printf("%s %c %s = %s\n", s1, op, s2, s ) ;
	
	
 	return 0 ;
 }