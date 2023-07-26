#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

#include "linked-list.h"

/*
 * linked-list.c
 * author:
 * date:
 *
 * Honor code:
 *
 */

int main(int argc, char * argv[]) {
 	struct Node * ll ;
 	int i ;
 	
 	ll = make_empty_list() ;
 	for (i=1;i<argc;i++) {
 		push_list(ll,argv[i]) ;
 	}
 	print_list(ll) ;
 	return 0 ;
 }