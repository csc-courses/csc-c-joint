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
	for (i=0;i<depth;i++) printf(" ") ;
	if (!node) {
		printf("%d:\n", depth) ;
		return ;
	}
	printf("%d:%s\n",depth, node->value) ;
	//printf("(") ;
	print_tree_aux(node->left, depth+1) ;
	//printf(")(") ;
	print_tree_aux(node->right, depth+1) ;
	//printf(")") ;
 	return ;
}

void print_tree(struct Node * root) {
	//printf("(") ;
	print_tree_aux(root->right, 0) ;
	//printf(")\n") ;
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

void insert_item(struct Node * root, char * item ) {
	struct Node * prev = root ;
	struct Node * next = prev->right ;
	struct Node * new ;
	
	new = (struct Node *) malloc(sizeof(struct Node)) ;
	new->value = strdup(item) ;
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

struct Parent find_item(struct Node * root, char * item ) {
	struct Node * prev = root ;
	struct Node * next = prev->right ;
	int r ; 
	struct Parent parent ;
	parent.parent = NULL ;
	
	r = strcmp(item, next->value) ;
	while (r) {
		if (r<0) {
			prev = next ;
			next = next->left ;
			parent.is_rightchild = 0 ;
		}
		else {  // r>0
			prev = next ;
			next = next->right ;
			parent.is_rightchild = 1 ;
		}
		if (!next) {
			return parent ;
		}
		r = strcmp(item, next->value) ;
	}
	parent.parent = prev ;
	return parent ;
}

void easy_remove_case(struct Parent * parent) {
	struct Node * a_child ;
	struct Node * to_remove ;
	struct Node * p = parent->parent ;

	to_remove = (parent->is_rightchild)? p->right : p->left ;
	a_child = (to_remove->left)? to_remove->left : to_remove->right ;
	
	if (parent->is_rightchild)
		p->right = a_child ;
	else 
		p->left = a_child ;

	free(to_remove->value) ;
	free(to_remove) ;
	return ;
}

char * hard_remove_case(struct Parent * parent) {
	struct Node * prev ;
	struct Node * next ;
	struct Node * p = parent->parent ;
	char * item ;
	int is_right ;

	prev = (parent->is_rightchild)? p->right : p->left ;
	next = prev->left ;
	parent->is_rightchild = 0 ;

	// keep going right until you can't
	while (next->right) {
		parent->is_rightchild  = 1 ; // we currently are a right child
		prev = next ;
		next = next->right ;
	}
	item = strdup(next->value) ; // because the removal will free the orginal
	parent->parent = (parent->is_rightchild)?next:prev ;
	easy_remove_case(parent) ;

	return item ;
}

int remove_item(struct Node * root, char * item ) {
	struct Parent parent ;
	struct Node * n ;
	int is_right ; 
	
	
	parent = find_item(root, item) ;
	if (!parent.parent) return 0 ;
	n = (parent.is_rightchild)? parent.parent->right : parent.parent->left ;
	if (!n->right || !n->left) 
		easy_remove_case(&parent) ;
	else
		n->value = hard_remove_case(&parent) ;

	return 0 ;
}


