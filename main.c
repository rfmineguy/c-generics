#include "chash_tplt.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define BUCKET_COUNT 10
HT_DEF(str, int, const char*, int);
HT_PUT_PROTO(str, int, const char*, int);
HT_GET_PROTO(str, int, const char*, int);
HT_HASH_PROTO(str, int, const char*, int);
HT_FREE_PROTO(str, int, const char*, int);
HT_CMP_PROTO(str, int, const char*, int);

HT_CMP_DEF(str, int, const char*, int) {
	return strcmp(key1, key2) == 0;
}
HT_HASH_DEF(str, int, const char*, int) {
	unsigned long hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % BUCKET_COUNT;
}
HT_GET_IMPL(str, int, const char*, int, -1)
HT_PUT_IMPL(str, int, const char*, int)
HT_FREE_IMPL(str, int, const char*, int)

int main() {
	ht_str_int ht = {0};
	ht_str_int_put(&ht, "test", 9);
	int v;
	if ((v = ht_str_int_get(&ht, "test"))) {
		printf("Found test: %d\n", v);
	}

	ht_str_int_free(&ht);
}
