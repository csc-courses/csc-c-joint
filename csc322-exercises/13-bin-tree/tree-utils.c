#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#include "tree-utils.h"

/*
 * tree-utils.c
 * author:
 * date:
 *
 * Honor code:
 *
 */
 
  
struct Node * make_empty_tree() {
	struct Node * node ;
	node = (struct Node *) malloc(sizeof(struct Node)) ;
	node->value = "" ;
	node->left = node->right = NULL ;
	return node ;
}

void print_tree_aux(struct Node * node, int depth) {
	int i ;
	if (!node) {
		printf("(%d:)", depth) ;
		return ;
	}
	printf("%d:%s",depth, node->value) ;
	printf("(") ;
	print_tree_aux(node->left, depth+1) ;
	printf(")(") ;
	print_tree_aux(node->right, depth+1) ;
	printf(")") ;
 	return ;
}

void print_tree(struct Node * root) {
	printf("(") ;
	print_tree_aux(root->right, 0) ;
	printf(")\n") ;
	return ;
}

void print_inorder_aux(struct Node * node ) {
	if (!node) return ;
	print_inorder_aux(node->left) ;
	printf("%s ", node->value) ;
	print_inorder_aux(node->right) ;
	return ;
}

void print_inorder(struct Node * root ) {
	print_inorder_aux(root->right) ;
	printf("\n") ;
	return ;
}

void insert_tree(struct Node * root, char * value ) {
	struct Node * prev = root ;
	struct Node * next = prev->right ;
	struct Node * new ;
	
	new = (struct Node *) malloc(sizeof(struct Node)) ;
	new->value = strdup(value) ;
	new->left = new->right = NULL ;
	
	while (next) {
		prev = next ;
		if (strcmp(new->value, prev->value)>=0) 
			next = next->right ;
		else next = next->left ;
	}
	if (strcmp(new->value, prev->value)>=0) 
		prev->right = new ;
	else prev->left = new ;
	return ;
}

