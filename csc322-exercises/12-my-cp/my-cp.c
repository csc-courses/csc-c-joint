#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>
#include <unistd.h>

/*
 * my-cp.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
#define BUF_SIZE 64
#define USAGE_MESSAGE "my-cp [-a] infile outfile"

int main(int argc, char * argv[]) {
	int ch, n_bytes ;
	int is_append = 0 ;
	int is_nocreate = 0 ;
	FILE * f_in, * f_out ;
	char buf[BUF_SIZE] ;

	while ((ch = getopt(argc, argv, "a")) != -1) 
		switch(ch) {
			case 'a':
				is_append = 1 ;
				break ;
			default:
				printf("%s\n", USAGE_MESSAGE) ;
				return 0 ;
		}
	argc -= optind;
	argv += optind;

	if (argc!=2) {
		printf("%s\n", USAGE_MESSAGE) ;
		return -1 ;
	}

	f_in = fopen(argv[0], "r") ;
	if (!f_in) {
		perror(argv[0]) ;
		return -1 ;
	}
	f_out = fopen(argv[1], (is_append)?"a":"w") ;
	if (!f_out) {
		perror(argv[1]) ;
		return -1 ;
	}

	while (!feof(f_in)) {
		n_bytes = fread(buf, sizeof(char), sizeof(buf), f_in) ;
		if (ferror(f_in)) {
			perror(argv[0]) ;
			return -1 ;
		}
		if ( n_bytes!=fwrite(buf, sizeof(char), n_bytes, f_out)) {
			perror(argv[1]) ;
			return -1 ; 
		}
	}
	fclose(f_in) ;
	fclose(f_out) ;
	return 0 ;
}