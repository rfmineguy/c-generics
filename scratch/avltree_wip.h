#ifndef AVL_H
#define AVL_H

typedef struct avl_int_node_t {
	int value;
	struct avl_int_node_t *left, *right, *parent;
} avl_int_node_t;

typedef struct avl_int_t {
	struct avl_int_node_t *root;
} avl_int_t;

int  avl_int_height(avl_int_t*);
void avl_int_insert(avl_int_t*, int);

#endif
