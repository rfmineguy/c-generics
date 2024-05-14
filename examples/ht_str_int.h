#ifndef HT_STR_INT_H
#define HT_STR_INT_H
#include "../chash_tplt.h" // This should point to wherever you have the chash_tplt file

#define BUCKET_COUNT 10
HT_DEF(str, int, const char*, int);
HT_PUT_PROTO(str, int, const char*, int);
HT_GET_PROTO(str, int, const char*, int);
HT_HASH_PROTO(str, int, const char*, int);
HT_FREE_PROTO(str, int, const char*, int);
HT_CMP_PROTO(str, int, const char*, int);

#endif
