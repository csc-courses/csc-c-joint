#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>

#include "tree-utils.h"

/*
 * bin-tree.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

#define BUF_LEN 1024
#define DELIMIT " \t\n"
#define USAGE_MESSAGE "bin-tree [-s]"

int main(int argc, char * argv[]) {
 	struct Node * root ;
 	char buf[BUF_LEN] ;
 	char * s ;
 	int ch, is_sort = 0 ;
 	
 	while ((ch = getopt(argc, argv, "s")) != -1) 
		switch(ch) {
			case 's':
				is_sort = 1 ;
				break ;
			default:
				printf("%s\n", USAGE_MESSAGE) ;
				return 0 ;
		}
	argc -= optind;
	argv += optind;

 	root = make_empty_tree() ;

 	
 	while (fgets(buf, sizeof(buf), stdin)) {
 		s = strtok(buf, DELIMIT) ;
 		while (s) {
 			insert_tree(root, s) ;
 			s = strtok(NULL, DELIMIT) ;
 		}
 	}
 	
 	if (is_sort) print_inorder(root) ;
 	else print_tree(root) ;
 	
 	return 0 ;
 }