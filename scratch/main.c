#include "redblacktree_wip.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void shuffle(int* arr, size_t len) {
	for (int i = 0; i < 100; i++) {
		int randindex1 = rand() % len; 
		int randindex2 = rand() % len;
		int t = arr[randindex1];
		arr[randindex1] = arr[randindex2];
		arr[randindex2] = t;
	}
}


// void numbers(bool should_shuffle) {
// 	const int SIZE = 4;
// 	int values[SIZE] = {0,1,2,3};
// 	if (should_shuffle)
// 		shuffle(values, SIZE);
// 	for (int i = 0; i < SIZE; i++) {
// 		printf("%d, ", values[i]);
// 	}
// 	printf("\n");
// 
// 	rb_tree_int rb = {0};
// 	for (int i = 0; i < SIZE; i++) {
// 		// printf("%d\n", values[i]);
// 		rb_insert(&rb, values[i]);
// 		rb_print(&rb);
// 	}
// 	rb_rotate_left(&rb.root);
// 	rb_print(&rb);
// }

void manual() {
	const int SIZE = 4;
	int values[SIZE] = {1, 2, 3, 4};

	rb_tree_int rb = {0};
	for (int i = 0; i < SIZE; i++) {
		rb_insert(&rb, values[i]);
		rb_print(&rb);
	}
	// rb_rotate_left(&rb.root->right, rb.root->right);
	rb_print(&rb);
}

int main() {
	srand(time(NULL));
	// numbers(true);
	// numbers(false);
	manual();
}
