#include "ht_str_struct.h"
#include <string.h>
#include <stdlib.h>

HT_CMP_DEF(str, tstruct, const char*, tstruct) {
	return strcmp(key1, key2) == 0;
}

HT_HASH_DEF(str, tstruct, const char*, tstruct) {
	unsigned long hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % BUCKET_COUNT;
}

HT_GET_IMPL(str, tstruct, const char*, tstruct, ((tstruct){.x=-1, .c=' ', .str = ""}))
HT_PUT_IMPL(str, tstruct, const char*, tstruct)
HT_FREE_IMPL(str, tstruct, const char*, tstruct)
