#include "ht_str_int.h"
#include <string.h>
#include <stdlib.h>

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
