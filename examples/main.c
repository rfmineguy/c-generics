#include "ht_str_int.h"
#include "ht_str_struct.h"
#include "maxheap_int.h"
#include "clist_int.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void list_int() {
	ll_int list;
	ll_int_append(&list, 3);
	ll_int_append(&list, 5);
	ll_int_append(&list, 6);
	ll_int_prepend(&list, 6);
	ll_int_print(&list);
	if (ll_int_contains(&list, 3)) {
		printf("list contains 3\n");
	}
	ll_int_delete(&list, 5);
	ll_int_print(&list);
	if (!ll_int_contains(&list, 3)) {
		printf("list doesnt contain 3\n");
	}
	ll_int_free(&list);
}

void max_heap_int() {
	heap_max_int heap;
	heap_max_int_enqueue(&heap, 3);
	heap_max_int_enqueue(&heap, 9);
	heap_max_int_enqueue(&heap, 5);
	heap_max_int_enqueue(&heap, 10);
	heap_max_int_enqueue(&heap, 4);
	heap_max_int_enqueue(&heap, 8);
	for (int i = 0; i < heap.size; i++) {
		printf("%d, ", heap.data[i]);
	}
	printf("\n");


	int v;
	while ((v = heap_max_int_dequeue(&heap)) != -1) {
		printf("%d\n", v);
	}
	for (int i = 0; i < heap.size; i++) {
		printf("%d, ", heap.data[i]);
	}
}

void ht_str_int_() {
	ht_str_int ht = {0};
	ht_str_int_put(&ht, "test", 9);
	int v;
	if ((v = ht_str_int_contains_key(&ht, "test"))) {
		printf("Found test: %d\n", v);
	}
	if (ht_str_int_contains_value(&ht, 9)) {
		printf("9 is present\n");
	}

	ht_str_int_remove_key(&ht, "test");
	if (!ht_str_int_contains_value(&ht, 9)) {
		printf("Removed 9: Success\n");
	}
	else {
		printf("Failed to remove key: %s -> %d\n", "test", ht_str_int_get(&ht, "test"));
	}
	ht_str_int_free(&ht);
}

void ht_str_struct_() {
	ht_str_tstruct ht = {0};
	ht_str_tstruct_put(&ht, "test", (tstruct) {.x = 4,.c = '4',.str="4"});
	tstruct v;
	if ((v = ht_str_tstruct_get(&ht, "test")).x != STR_STRUCT_DEFAULT.x) {
		printf("Found test: %d\n", v.x);
	}
	if (ht_str_tstruct_contains_value(&ht, (tstruct) {.x = 4, .c = '4', .str = "4"})) {
		printf("Found test by value\n");
	}
	ht_str_tstruct_free(&ht);
}

int main() {
	ht_str_int_();
	ht_str_struct_();
	max_heap_int();
	list_int();
}
