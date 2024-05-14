#include "ht_str_int.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
	ht_str_int ht = {0};
	ht_str_int_put(&ht, "test", 9);
	int v;
	if ((v = ht_str_int_get(&ht, "test"))) {
		printf("Found test: %d\n", v);
	}

	ht_str_int_free(&ht);
}
