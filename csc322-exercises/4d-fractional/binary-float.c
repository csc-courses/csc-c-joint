#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


/*
 * title: binary-float.c
 * last-update:
 *     3 sep 2023 -bjr:
 *
 * Honor code:
 *
 */


#define DEBUG 0

#define WITH_COMMAS 4
//#undef WITH_COMMAS

void print_binary_aux(int b, int prec) {
	int bit ; 
	
	if (prec==0) return ;
	bit = b%2 ;
	print_binary_aux(b/2, prec-1) ;
	
#ifdef WITH_COMMAS
	if (prec==1) printf(".") ;
	else if ((prec-1)%WITH_COMMAS==0) printf(",") ;
#endif
	printf("%c", (bit)?'1':'0') ;
	
	return ;
}

void print_bin_mantissa(int b, int prec) {
	int bits = 0 ;
	printf("0b") ;
	if (b==0) {
		printf(".0") ;
		return ;
	}
	print_binary_aux(b, prec) ;
	return ;
}


int frac_dec_to_bin(int d_n, int d_p, int b_p) {
	// given a number r = d_n/10e(d_p) 
	// find b_n so that r = b_n/10e(b_p) (as close as possible)
	
	int b_n = 0 ;
	int i, bit ;
	int denom = pow(10,d_p) ;
	
	for (i=0;i<b_p;i++) {
		bit = 0 ;
		d_n *= 2 ;
		if (d_n>=denom) {
			d_n -= denom ;
			bit = 1 ;
		}
		b_n = 2*b_n+bit ;	
	}
	return b_n ;
}

int frac_bin_to_dec(int b_n, int b_p, int d_p) {
	int d_n = 0 ;
	int i, digit ;
	int denom = pow(2,b_p) ;
	
	for (i=0;i<d_p;i++) {
		digit = 0 ;
		b_n *= 10 ;
		if (b_n>=denom) {
			digit = b_n / denom ;
			b_n -= digit*denom ;
		}
		d_n = 10*d_n + digit ;
	}
	return d_n ;
}

int main(int argc, char * argv[]) {
	
	int bin_precision = atoi(argv[1]) ;
	int dec_numerator = atoi(argv[2]) ;
	int dec_precision = strlen(argv[2]) ;
	int bin_numerator = 0 ;
	float f ; 
	
	f = dec_numerator/pow(10,dec_precision) ;
	printf("decimal fraction: %d/10e%d = %f\n",  dec_numerator, dec_precision, f) ;
	
	bin_numerator = frac_dec_to_bin(dec_numerator, dec_precision, bin_precision) ;
	f = bin_numerator/pow(2,bin_precision) ;
	printf("binary fraction: %d/2e%d = %f\n",  bin_numerator, bin_precision, f) ;
	printf("binary mantissa: ") ;
	print_bin_mantissa(bin_numerator, bin_precision) ;
	printf("\n", bin_precision) ;
	
	dec_numerator = frac_bin_to_dec(bin_numerator, bin_precision, 7 ) ;
	f = dec_numerator/pow(10,7) ;
	printf("decimal fraction: %d/10e%d = %f\n",  dec_numerator, 7, f) ;

	
 	return 0 ;
 }