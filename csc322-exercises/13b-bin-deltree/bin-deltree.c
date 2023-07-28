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
#define USAGE_MESSAGE "bin-tree [-v]"

int main(int argc, char * argv[]) {
	struct Node * root ;
	char buf[BUF_LEN] ;
	char * s ;
	int ch, is_verbose = 0 ;
	int expect_nottofind = 0 ;
	struct Parent parent ;

	while ((ch = getopt(argc, argv, "v")) != -1) 
		switch(ch) {
			case 'v':
				is_verbose++ ;
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
			switch (s[0]) {
			case '^':
				print_tree(root) ;
				break ;
			case '>':
				print_inorder(root) ;
				break ;
			case '~':
				expect_nottofind = 1 ;
			case '=':
				parent = find_item(root,s+1) ;
				if (!parent.parent != !expect_nottofind)
					printf("error: |%s| %sfound\n", s+1, (parent.parent)?"":"not ") ;
				expect_nottofind = 0 ;
				break ;
			case '+':
				s += 1 ;
			case '-':
				remove_item(root,s+1) ;
				break ;
			default:
				insert_item(root, s) ;
				break ;
			}
		
			s = strtok(NULL, DELIMIT) ;
		}
	} 	
	return 0 ;
}