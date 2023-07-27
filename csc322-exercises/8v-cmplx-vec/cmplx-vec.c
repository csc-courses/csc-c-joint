#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

#include "cmplx-util.h"

/*
 * cmplx-vec.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

#define DIM 3
#define DELIMIT " \t,"
#define BUF_SIZE 1024

int read_complex_vector(struct Complex v[], int dim, char * in_buf ) {
	char * s, * r ;
	int i ;
	r = in_buf ;

	for (i=0; i<dim; i++) {
		s = strtok(r, DELIMIT) ;
		if (!s) return -1 ;
		v[i].real = atof(s) ;
		s = strtok(NULL, DELIMIT) ;
		if (!s) return -1 ;
		v[i].imag = atof(s) ;
		r = NULL ;
	}
	return 0 ;
}

int main(int argc, char * argv[]) {

	char buf[BUF_SIZE] ;
	struct Complex v1[DIM] ;
	struct Complex v2[DIM] ;
	struct Complex c ;
	int i, res  ;
	
	if (!fgets(buf, BUF_SIZE, stdin )) {
		return -1 ;
	}
	res = read_complex_vector(v1, DIM, buf) ;
	if (res) {
		printf("error: read_complex_number returns %d\n", res ) ;
		return 0 ;
	}

	if (!fgets(buf, BUF_SIZE, stdin )) {
		return -1 ;
	}
	res = read_complex_vector(v2, DIM, buf) ;
		if (res) {
		printf("error: read_complex_number returns %d\n", res ) ;
		return 0 ;
	}

	printf("v1:\t\t") ;
	cmplx_printf_v(v1, DIM) ;
	printf("v2:\t\t") ;
	cmplx_printf_v(v2, DIM) ;
	
	c = cmplx_inner(v1, v2, DIM ) ;
	printf("<v1,v2>:\t") ;
	cmplx_printf(&c) ;
	
 	return 0 ;
 }