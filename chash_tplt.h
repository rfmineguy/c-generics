#include <stdbool.h>

#define JOIN2(a, b) a ## b
#define JOIN3(a, b, c) a ## b ## c
#define JOIN4(a, b, c, d) a ## b ## c ## d
#define JOIN5(a, b, c, d, e) a ## b ## c ## d ## e

#define HT_MAIN_STRUCT_NAME(key_name, value_name) JOIN4(ht_, key_name, _, value_name)
#define HT_LL_STRUCT_NAME(key_name, value_name) JOIN3(ht_, value_name, _ll)

#define HT_STRUCT_DEF(key_name, value_name, key_type, value_type)\
typedef struct {\
    struct JOIN3(ht_, value_name, _ll)* buckets[BUCKET_COUNT]; \
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

#define HT_PUT_PROTO(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _put)(HT_MAIN_STRUCT_NAME(key_name, value_name)*, key_type, value_type)

#define HT_CONTAINS_KEY_PROTO(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _contains_key)(HT_MAIN_STRUCT_NAME(key_name, value_name)*, key_type)

#define HT_CONTAINS_VALUE_PROTO(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _contains_value)(HT_MAIN_STRUCT_NAME(key_name, value_name)*, value_type)

#define HT_REMOVE_KEY_PROTO(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _remove_key)(HT_MAIN_STRUCT_NAME(key_name, value_name)*, key_type)

#define HT_GET_PROTO(key_name, value_name, key_type, value_type)\
	value_type JOIN5(ht_, key_name, _, value_name, _get)(HT_MAIN_STRUCT_NAME(key_name, value_name)*, key_type)

#define HT_HASH_PROTO(key_name, value_name, key_type, value_type)\
	int JOIN5(ht_, key_name, _, value_name, _hash)(key_type)\

#define HT_FREE_PROTO(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _free)(HT_MAIN_STRUCT_NAME(key_name, value_name)*)\

#define HT_CMP_KEY_PROTO(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _cmpkey)(key_type, key_type)\

#define HT_CMP_VALUE_PROTO(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _cmpval)(value_type, value_type)\

#define HT_PUT_IMPL(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _put)(HT_MAIN_STRUCT_NAME(key_name, value_name) *ht, key_type key, value_type val) {\
		int hash = JOIN5(ht_, key_name, _, value_name, _hash)(key);\
		if (ht->buckets[hash] == NULL) {\
			ht->buckets[hash] = calloc(1, sizeof(HT_LL_STRUCT_NAME(key_name, value_name)));\
			ht->buckets[hash]->val = val;\
			ht->buckets[hash]->key = key;\
			return;\
		}\
		else {\
			HT_LL_STRUCT_NAME(key_name, value_name)* node = ht->buckets[hash];\
			while (node->next) node = node->next;\
			node = calloc(1, sizeof(HT_LL_STRUCT_NAME(key_name, value_name)));\
			node->val = val;\
			node->key = key;\
		}\
	}\

#define HT_CONTAINS_KEY_IMPL(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _contains_key)(HT_MAIN_STRUCT_NAME(key_name, value_name) *ht, key_type key) {\
		int hash = JOIN5(ht_, key_name, _, value_name, _hash)(key);\
		if (ht->buckets[hash] == NULL) {\
			return false;\
		}\
		else if (JOIN5(ht_, key_name, _, value_name, _cmpkey)(ht->buckets[hash]->key, key)){\
			return true;\
		}\
		else {\
			HT_LL_STRUCT_NAME(key_name, value_name)* node = ht->buckets[hash];\
			while (node && JOIN5(ht_, key_name, _, value_name, _cmpkey)(node->key, key)) node = node->next;\
			if (!node) return false;\
			return true;\
		}\
		return false;\
	}

#define HT_CONTAINS_VALUE_IMPL(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _contains_value)(HT_MAIN_STRUCT_NAME(key_name, value_name) *ht, value_type val) {\
		for (int i = 0; i < BUCKET_COUNT; i++) {\
			HT_LL_STRUCT_NAME(key_name, value_name)* node = ht->buckets[i];\
			while (node && !(JOIN5(ht_, key_name, _, value_name, _cmpval)(node->val, val))) node = node->next;\
			if (!node) continue;\
			return true;\
		}\
		return false;\
	}

#define HT_REMOVE_KEY_IMPL(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _remove_key)(HT_MAIN_STRUCT_NAME(key_name, value_name) *ht, key_type key) {\
		int hash = JOIN5(ht_, key_name, _, value_name, _hash)(key);\
		if (ht->buckets[hash] == NULL) {\
			return;\
		}\
		else if (JOIN5(ht_, key_name, _, value_name, _cmpkey)(ht->buckets[hash]->key, key)){\
			free(ht->buckets[hash]);\
			ht->buckets[hash] = NULL;\
		}\
		else {\
			HT_LL_STRUCT_NAME(key_name, value_name)* node = ht->buckets[hash];\
			HT_LL_STRUCT_NAME(key_name, value_name)* prev = NULL;\
			while (node && !(JOIN5(ht_, key_name, _, value_name, _cmpkey)(node->key, key))) {\
				prev = node;\
				node = node->next;\
			}\
			if (!prev || !node) return;\
			prev->next = node->next;\
			free(node);\
		}\
	}

#define HT_GET_IMPL(key_name, value_name, key_type, value_type, default)\
	value_type JOIN5(ht_, key_name, _, value_name, _get)(HT_MAIN_STRUCT_NAME(key_name, value_name) *ht, key_type key) {\
		int hash = JOIN5(ht_, key_name, _, value_name, _hash)(key);\
		if (ht->buckets[hash] == NULL) {\
			return default;\
		}\
		else if (JOIN5(ht_, key_name, _, value_name, _cmpkey)(ht->buckets[hash]->key, key)){\
			return ht->buckets[hash]->val;\
		}\
		else {\
			HT_LL_STRUCT_NAME(key_name, value_name)* node = ht->buckets[hash];\
			while (node && !(JOIN5(ht_, key_name, _, value_name, _cmpkey)(node->key, key))) node = node->next;\
			if (!node) return (default);\
			return node->val;\
		}\
	}\

#define HT_HASH_DEF(key_name, value_name, key_type, value_type)\
	int JOIN5(ht_, key_name, _, value_name, _hash)(key_type key)

#define HT_FREE_IMPL(key_name, value_name, key_type, value_type)\
	void JOIN5(ht_, key_name, _, value_name, _free)(HT_MAIN_STRUCT_NAME(key_name, value_name) *ht) {\
		for (int i = 0; i < BUCKET_COUNT; i++) {\
			HT_LL_STRUCT_NAME(key_name, value_name) *n = ht->buckets[i];\
			while (n) {\
				HT_LL_STRUCT_NAME(key_name, value_name) *t = ht->buckets[i];\
				n = n->next;\
				free(t);\
			}\
		}\
	}\

#define HT_CMP_KEY_DEF(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _cmpkey)(key_type key1, key_type key2)

#define HT_CMP_VALUE_DEF(key_name, value_name, key_type, value_type)\
	bool JOIN5(ht_, key_name, _, value_name, _cmpval)(value_type val1, value_type val2)
