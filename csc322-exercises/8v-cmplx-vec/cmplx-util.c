#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#include "cmplx-util.h"

/*
 * cmplx-util.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

#define CMPLX_FORMAT "%.2f%+.2fi "


void cmplx_printf(struct Complex * c ) {
	printf(CMPLX_FORMAT, c->real, c->imag) ;
	printf("\n") ;
	return ;
}

void cmplx_printf_v(struct Complex * c, int dim ) {
	int i ;
	printf("[ ") ;
	for (i=0;i<dim;i++) {	
		printf(CMPLX_FORMAT, c[i].real,c[i].imag) ;
	}
	printf("]\n") ;
	return ;
}

struct Complex * cmplx_copy(struct Complex * dst, struct Complex * src) {
	int i ;
	dst->real = src->real ;
	dst->imag = src->imag ;
	return dst ;
}

struct Complex * cmplx_add( struct Complex * sum, struct Complex * add ) {
	sum->real = sum->real + add->real ;
	sum->imag = sum->imag + add->imag ;
	return sum ;
}

struct Complex * cmplx_mult( struct Complex * prod, struct Complex * mul ) {
	struct Complex temp ;
	temp.real = prod->real ;
	temp.imag = prod->imag ;
	prod->real = (temp.real * mul->real) - (temp.imag * mul->imag) ;
	prod->imag = (temp.real * mul->imag) + (temp.imag * mul->real) ;
	return prod ;
}

struct Complex cmplx_inner( struct Complex * v1, struct Complex * v2, int dim ) {
	int i ;
	struct Complex d, t ;
	d.real = d.imag = 0.0 ;
	
	for (i=0; i<dim; i++) {
		cmplx_copy(&t, v2+i) ;
		t.imag = -t.imag ;
		cmplx_mult(&t, v1+i) ;
		cmplx_add( &d, &t) ;
	}
	return d ;
	
}
