#include "dgraph.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

HT_CMP_KEY_DEF(str, node, const char*, graph_node) {
	return strcmp(key1, key2) == 0;
}
HT_CMP_VALUE_DEF(str, int, const char*, int) {
	return val1 == val2;
}
HT_HASH_DEF(str, int, const char*, int) {
	unsigned long hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % BUCKET_COUNT;
}
HT_PUT_IMPL(str, node, const char*, graph_node);
HT_GET_IMPL(str, node, const char*, graph_node, (graph_node){.v = -INT_MAX})
HT_GET_PTR_IMPL(str, node, const char*, graph_node)
HT_REMOVE_KEY_IMPL(str, node, const char*, graph_node)
HT_CONTAINS_KEY_IMPL(str, node, const char*, graph_node)
HT_CONTAINS_VALUE_IMPL(str, node, const char*, graph_node)
HT_FREE_IMPL(str, node, const char*, graph_node)

void dgraph_add_vertex(dgraph_t* g, const char* key, int v) {
	ht_str_node_put(&g->node_hash, key, (graph_node){.v=v});
}

void dgraph_remove_vertex(dgraph_t* g, const char* v) {
}

void dgraph_add_edge(dgraph_t* g, const char* v_from, const char* v_to) {
	ht_node_ll* n = ht_str_node_get_ptr(&g->node_hash, v_from);
}

void dgraph_remove_edge(dgraph_t* g, const char* v_from, const char* v_to) {
}

int dgraph_get_vertex(dgraph_t* g, const char* v) {
}
