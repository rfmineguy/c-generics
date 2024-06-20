#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef enum rb_tree_color {
	RED, BLACK
} rb_tree_color;

typedef struct rb_tree_node_int {
	int v;
	rb_tree_color color;
	int black_depth;
	struct rb_tree_node_int *parent, *left, *right;
} rb_tree_node_int;

typedef struct {
	rb_tree_node_int *root;
} rb_tree_int;

void rb_insert(rb_tree_int*, int);
void rb_print(rb_tree_int*);
int  rb_black_depth_rec(rb_tree_node_int*);
void rb_rotate_left(rb_tree_node_int**, rb_tree_node_int*);
void rb_rotate_right(rb_tree_node_int**);
void rb_balance(rb_tree_int*, rb_tree_node_int*);

#endif
