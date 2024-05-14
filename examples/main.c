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
	if ((v = ht_str_int_get(&ht, "test"))) {
		printf("Found test: %d\n", v);
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
	ht_str_tstruct_free(&ht);
}

int main() {
	str_int();
	str_struct();
}
