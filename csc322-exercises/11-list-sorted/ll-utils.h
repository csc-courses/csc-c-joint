/*
 * header file for linked-list
 * author:
 * last-update:
 *    26 jul 2023
 */
 

struct Node {
	char * word ;
	struct Node * next ;
} ;
 
struct Node * make_empty_list() ;
void push_list(struct Node * ll, char * word) ;
void print_list(struct Node * ll) ;
struct Node * find_predecessor(struct Node * ll, char * word) ;
void insert_after(struct Node * n, char * word) ;
