#include "chash_tplt.h"
#include <stdlib.h>
#include <string.h>
HT_DEF(str, int, const char*, int);
HT_PROTOTYPES(str, int, const char*, int);
HT_HASH_IMPL(str, int, const char*) {
	int hash = 0;
	for (int i = 0; i < strlen(key); i++) {
		hash += key[i] * 3402;
	}
	return hash % 10;
}
HT_IMPL(str, int, const char*, int);

int main() {
	ht_str_int ht = {0};
	ht_str_int_put(&ht, "test", 1);
	int v = ht_str_int_get("test");
}
