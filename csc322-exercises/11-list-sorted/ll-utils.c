#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

#include "ll-utils.h"

/*
 * ll-utils.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
struct Node * make_empty_list() {
	struct Node * node ;
	node = (struct Node *) malloc(sizeof(struct Node)) ;
	node->word = "" ;
	node->next = NULL ;
	return node ;
}

void push_list(struct Node * ll, char * word) {
	struct Node * node ;
	node = (struct Node *) malloc(sizeof(struct Node)) ;
	node->word = strdup(word) ;
	node->next = ll->next ;
	ll->next = node ;
}

struct Node * find_predecessor(struct Node * ll, char * word) {
	struct Node * node, * pred ;
	pred = ll ;
	node = ll->next ;
	
	while (pred->next) {
		if (strcmp(word,node->word)<0) break ;
		pred = node ;
		node = node->next ;
	}
	return pred ;
}

void insert_after(struct Node * pred, char * word) {
	struct Node * node ;
	node = (struct Node *) malloc(sizeof(struct Node)) ;
	node->word = strdup(word) ;
	node->next = pred->next ;
	pred->next = node ;
	return ;
}


void print_list(struct Node * ll) {
	int i = 0 ;
	while (ll->next) {
		ll = ll->next ;
		printf("%d: %s\n", i, ll->word ) ;
		i++ ;
	}
	return ;
}

