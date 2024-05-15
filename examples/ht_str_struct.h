#ifndef HT_STR_STRUCT_H
#define HT_STR_STRUCT_H

#include "../templates/chash_tplt.h" // This should point to wherever you have the chash_tplt file

typedef struct {
	int x;
	char c;
	const char* str;
} tstruct;

#define BUCKET_COUNT 10
#define STR_STRUCT_DEFAULT (tstruct){.x=1, .c=' ', .str=" "}
HT_DEF(str, tstruct, const char*, tstruct);
HT_PUT_PROTO(str, tstruct, const char*, tstruct);
HT_CONTAINS_KEY_PROTO(str, tstruct, const char*, tstruct);
HT_CONTAINS_VALUE_PROTO(str, tstruct, const char*, tstruct);
HT_GET_PROTO(str, tstruct, const char*, tstruct);
HT_HASH_PROTO(str, tstruct, const char*, tstruct);
HT_FREE_PROTO(str, tstruct, const char*, tstruct);
HT_CMP_KEY_PROTO(str, tstruct, const char*, tstruct);
HT_CMP_VALUE_PROTO(str, tstruct, const char*, tstruct);

#endif
