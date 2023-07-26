#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

#include "cmplx-util.h"

/*
 * cmplx-num.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

#define DIM 1
#define DELIMIT " \t,"
#define BUF_SIZE 1024

int read_complex_number(struct Complex * v, char * in_buf ) {
	char * s ;
	
	s = strtok(in_buf, DELIMIT) ;
	if (!s) return -1 ;
	v->real = atof(s) ;
	s = strtok(NULL, DELIMIT) ;
	if (!s) return -1 ;
	v->imag = atof(s) ;

	return 0 ;
}

int main(int argc, char * argv[]) {

	char buf[BUF_SIZE] ;
	struct Complex c1, c2, c3 ;
	int res, i ;
	
	if (!fgets(buf, BUF_SIZE, stdin )) {
		return -1 ;
	}
	
	res = read_complex_number(&c1, buf) ;
	if (res) {
		printf("error\n") ;
		return 0 ;
	}
	
	if (!fgets(buf, BUF_SIZE, stdin )) {
		return -1 ;
	}
	
	res = read_complex_number(&c2, buf) ;
	if (res) {
		printf("error: read_complex_number returns %d\n", res ) ;
		return 0 ;
	}

	printf("c1:\t") ;
	cmplx_printf(CMPLX_FORMAT, &c1) ;
	
	printf("c1:\t") ;
	cmplx_printf(CMPLX_FORMAT, &c2) ;

	cmplx_copy(&c3, &c1 ) ;
	cmplx_add(&c1, &c2 ) ;
	printf("c1+c2:\t") ;
	cmplx_printf(CMPLX_FORMAT, &c1) ;
	
	cmplx_copy(&c1, &c3) ;
	cmplx_mult(&c1, &c2 ) ;
	printf("c1*c2:\t") ;;
	cmplx_printf(CMPLX_FORMAT, &c1) ;

 	return 0 ;
 }