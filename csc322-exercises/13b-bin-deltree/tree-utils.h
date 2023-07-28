/*
 * header file for binary tree
 * author:
 * last-update:
 *    27 jul 2023
 */
 

struct Node {
	char * value ;
	struct Node * left ;
	struct Node * right ;
} ;

struct Parent {
	struct Node * parent ;
	int is_rightchild ;
} ;
 
struct Node * make_empty_tree() ;
void print_tree(struct Node * root) ;
void print_inorder(struct Node * root ) ;
void insert_item(struct Node * root, char * item ) ;
struct Parent find_item(struct Node * root, char * item ) ; 
int remove_item(struct Node * root, char * item ) ;

