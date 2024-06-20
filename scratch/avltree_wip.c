#include "avltree_wip.h"
#include <stdlib.h>

avl_int_node_t* avl_int_insert_rec(avl_int_node_t** n, avl_int_node_t* parent, int v) {
	if (*n == NULL) {
		*n = calloc(1, sizeof(avl_int_node_t));
		(*n)->value = v;
		(*n)->parent = parent;
		return *n;
	}
	if (v < (*n)->value) {
		return avl_int_insert_rec(&(*n)->left, *n, v);
	}
	else {
		return avl_int_insert_rec(&(*n)->right, *n, v);
	}
}

int avl_int_height_rec(avl_int_node_t *n, int height) {
	if (n->left) {
		return avl_int_height_rec(n->left, height + 1);
	}
	if (n->right) {
		return avl_int_height_rec(n->right, height + 1);
	}
}

int avl_int_height(avl_int_t *avl) {
	return avl_int_height_rec(avl->root, 0);
}

void avl_int_insert(avl_int_t *avl, int v) {
	avl_int_node_t* n = avl_int_insert_rec(&avl->root, NULL, v);
}
