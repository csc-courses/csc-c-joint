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

void cmplx_printf(char * format, struct Complex * c ) {
	char sign ;
	sign = (c->imag<0.0) ? '-' : '+' ;
	printf(format, c->real, sign, fabs(c->imag)) ;
	return ;
}

struct Complex * cmplx_copy(struct Complex * dst, struct Complex * src) {
	int i ;
	dst->real = src->real ;
	dst->imag = src->imag ;
	return dst ;
}

struct Complex * cmplx_conj( struct Complex * c ) {
	c->real = c->real ;
	c->imag = -c->imag ;
	return c ;
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
