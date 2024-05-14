#define JOIN2(a, b) a ## b
#define JOIN3(a, b, c) a ## b ## c
#define JOIN4(a, b, c, d) a ## b ## c ## d
#define JOIN5(a, b, c, d, e) a ## b ## c ## d ## e

#define HT_MAIN_STRUCT_NAME(key_name, value_name) JOIN4(ht_, key_name, _, value_name)
#define HT_LL_STRUCT_NAME(key_name, value_name) JOIN3(ht_, value_name, _ll)

#define HT_STRUCT_DEF(key_name, value_name, key_type, value_type)\
typedef struct {\
    struct JOIN3(ht_, value_name, _ll)* buckets[10]; \
} HT_MAIN_STRUCT_NAME(key_name, value_name);

#define HT_NODE_DEF(key_name, value_name, key_type, value_type)\
typedef struct HT_LL_STRUCT_NAME(key_name, value_name) {\
    key_type key;\
    value_type val;\
    struct HT_LL_STRUCT_NAME(key_name, value_name) *next;\
} HT_LL_STRUCT_NAME(key_name, value_name);

#define HT_DEF(key_name, value_name, key_type, value_type)\
	HT_NODE_DEF(key_name, value_name, key_type, value_type)\
	HT_STRUCT_DEF(key_name, value_name, key_type, value_type)\

#define HT_PROTOTYPES(key_name, value_name, key_type, value_type)\
	void       JOIN5(ht_, key_name, _, value_name, _put)(HT_MAIN_STRUCT_NAME(key_name, value_name)*, key_type, value_type);\
	value_type JOIN5(ht_, key_name, _, value_name, _get)(key_type);\
	int        JOIN5(ht_, key_name, _, value_name, _hash)(key_type key);

#define HT_HASH_IMPL(key_name, value_name, key_type)\
	int JOIN5(ht_, key_name, _, value_name, _hash)(key_type key)

#define HT_IMPL(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _put)(JOIN4(ht_, key_name, _, value_name) *ht, key_type key, value_type val) {\
		int hash = JOIN5(ht_, key_name, _, value_name, _hash)(key);\
		if (ht->buckets[hash] == NULL) {\
			ht->buckets[hash] = calloc(1, sizeof(ht->buckets[0]));\
		}\
	}\
