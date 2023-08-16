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
#define DELIMIT " \t,"

char * int_to_hex(char * buf, int size, int d) {
	int i, n ;
	char map_chars[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'} ;
	i = size ;
	buf[i] = '\0' ;
	
	for (i=i-1;i>=0;i--) {
		buf[i] = map_chars[d&0xf] ;
		d >>= 4 ;
	}
	return buf ;
}

char * int_to_bin(char * buf, int size, int d) {
	int i, n ;
	i = size ;
	buf[i] = '\0' ;
	
	for (i=i-1;i>=0;i--) {
		buf[i] = (d&0x1)?'1':'0' ;
		d >>= 1 ;
	}
	return buf ;
}


int main(int argc, char * argv[]) {
	short d ;
	char * s ;
	char buf[BUF_SIZE] ;
	char bin_repre[8*sizeof(short)+1] ;
	char hex_repre[2*sizeof(short)+1] ;
	
	if (!fgets(buf, BUF_SIZE, stdin )) {
		return -1 ;
	}

	s = strtok(buf,DELIMIT) ;
	d = atoi(s) ;
	int_to_hex(hex_repre, sizeof(hex_repre), d) ;
	int_to_bin(bin_repre, sizeof(bin_repre), d) ;
	printf("%d:\t0x%s\t0b%s\n", d, hex_repre, bin_repre) ;
	
	while ((s=strtok(NULL,DELIMIT))) {
		d = atoi(s) ;
		int_to_hex(hex_repre, sizeof(hex_repre), d) ;
		int_to_bin(bin_repre, sizeof(bin_repre), d) ;
		printf("%d:\t0x%s\t0b%s\n", d, hex_repre, bin_repre) ;
	}
 	return 0 ;
 }