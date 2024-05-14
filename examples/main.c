#include "ht_str_int.h"
#include "ht_str_struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void str_int() {
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

void str_struct() {
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
	str_int();
	str_struct();
}
