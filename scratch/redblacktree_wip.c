#include "redblacktree_wip.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int rb_black_depth_rec(rb_tree_node_int* node) {
	if (node == NULL) return 0;
	int left  = rb_black_depth_rec(node->left);
	int right = rb_black_depth_rec(node->right);
	node->black_depth = ((right > left) ? right : left) + (node->color == BLACK);
	return node->black_depth;
}

void rb_insert_rec(rb_tree_node_int** node, rb_tree_node_int* parent, rb_tree_node_int** out, int v) {
	if (*node == NULL) {
		*node = calloc(1, sizeof(rb_tree_node_int));
		(*node)->v = v;
		(*node)->color = RED;
		(*node)->parent = parent;
		*out = *node;
		return;
	}
	if (v > (*node)->v) {
		rb_insert_rec(&(*node)->right, *node, out, v);
	}
	else {
		rb_insert_rec(&(*node)->left, *node, out, v);
	}
}

void rb_print_rec(rb_tree_node_int* node, rb_tree_node_int* parent, int depth) {
	if (node == NULL) {
		printf("%*c\\_NULL\n", depth * 2, ' ');
		return;
	}
	printf("%*c\\_%d (%s)   parent: %d\n", depth * 2, ' ', node->v, node->color == RED ? "Red" : "Black", parent ? parent->v : -1);
	rb_print_rec(node->left, node, depth + 1);
	rb_print_rec(node->right, node, depth + 1);
}

void rb_insert(rb_tree_int* rb, int v) {
	rb_tree_node_int* out;
	rb_insert_rec(&rb->root, NULL, &out, v);
	if (out == rb->root) {
		rb->root->color = BLACK;
	}
	// printf("root=%p\n", rb->root);
	rb_print(rb);
	rb_balance(rb, out);
}

void rb_print(rb_tree_int* rb) {
	rb_print_rec(rb->root, NULL, 0);
	printf("\n");
}

void rb_balance(rb_tree_int* rb, rb_tree_node_int* new_node) {
	bool has_parent      = new_node->parent != NULL;
	bool has_gp          = has_parent && new_node->parent->parent != NULL;
	bool has_left_uncle  = has_gp && new_node->parent->parent->left != NULL;
	bool has_right_uncle = has_gp && new_node->parent->parent->right != NULL;
	bool is_right_node   = has_parent && new_node == new_node->parent->right;
	bool is_left_node    = has_parent && new_node == new_node->parent->left;

	/* case:   line, right, no uncle
	 *    G 									P
	 *     \ 								 / \
	 *      P         ->    G   N
	 *       \
	 *        N
	 */
	if (is_right_node && has_gp && !has_left_uncle && new_node->parent->color == RED) {
		// printf("line, right, no uncle\n");
		rb_tree_node_int** p  = &(new_node->parent);
		rb_tree_node_int** gp = &(new_node->parent->parent);

		printf("root==?gp = %s\n", rb->root == *gp ? "true" : "false"); 
		printf("root=%p\n", rb->root);
		rb_rotate_left(&new_node->parent->parent, new_node->parent->parent);
		printf("&p=%p\n", *p);
		printf("root==?p = %s\n", rb->root == *p ? "true" : "false"); 
		printf("root=%p\n", rb->root);
		return;
	}
	/* case:   opposite-line, left, no uncle
	 *      G
	 *     /
	 *    P
	 *   /
	 *  N
	 */
	// if (is_left_node && has_gp && !has_right_uncle && p_new_node->parent->color == RED) {
	// 	printf("opposite line, left, no uncle\n");
	// 	rb_tree_node_int** p  = &(*new_node)->parent;
	// 	rb_tree_node_int** gp = &(*new_node)->parent->parent;
	// 	rb_rotate_right(gp);
	// 	(*gp)->color = (*p)->color;
	// }
	/* case:   arrow, left, no uncle
	 *    G
	 *     \
	 *      P
	 *     /
	 *    N
	 */
	// if (is_left_node && has_gp && !has_left_uncle && p_new_node->parent->color == RED) {
	// 	printf("arrow, left, no uncle\n");
	// 	printf("gp = %d\n", p_new_node->parent->parent->v);
	// 	rb_tree_node_int** p = &(*new_node)->parent;
	// 	rb_tree_node_int** gp = &(*new_node)->parent->parent;
	// 	rb_rotate_right(p);
	// 	//rb_rotate_left(gp);
	// }
	/* case:   arrow, right, no uncle
	 *    G
	 *   /
	 *  P
	 *   \
	 *    N
	 */
	// if (is_right_node && has_gp && !has_right_uncle && p_new_node->parent->color == RED) {
	// 	printf("arrow, right, no uncle\n");
	// 	rb_tree_node_int** p =  &(*new_node)->parent;
	// 	rb_tree_node_int** gp = &(*new_node)->parent->parent;
	// 	rb_rotate_left(p);
	// 	rb_rotate_right(gp);
	// }
}

void rb_rotate_left(rb_tree_node_int** root, rb_tree_node_int* node) {
	printf("%p\n", *root);
	node->parent = node->right;
	node->right = node->right->left;
	if (node->right) {
		node->right->parent = node;
	}
	node->parent->left = node;
	if (node->parent == NULL)
		*root = node;
	else
		*root = node->parent;
	printf("%p\n", *root);
}

void rb_rotate_right(rb_tree_node_int** root) {
	rb_tree_node_int* parent = (*root)->parent;
	rb_tree_node_int* right = (*root)->right;
	rb_tree_node_int* left = (*root)->left;
	rb_tree_node_int* left_right = left->right;
	parent->right = left;
	left->right = (*root);

	(*root)->left = left_right;
	(*root) = left;
}
