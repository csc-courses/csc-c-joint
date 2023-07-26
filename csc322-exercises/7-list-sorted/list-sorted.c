#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

#include "ll-utils.h"

/*
 * linked-list.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

int main(int argc, char * argv[]) {
 	struct Node * ll, * pred ;
 	int i ;
 	
 	ll = make_empty_list() ;
 	for (i=1;i<argc;i++) {
 		pred = find_predecessor(ll, argv[i]) ;
 		insert_after(pred, argv[i]) ;
 	}
 	print_list(ll) ;
 	return 0 ;
 }