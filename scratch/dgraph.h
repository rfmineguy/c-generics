#ifndef DGRAPH_H
#define DGRAPH_H
#include "../templates/chash_tplt.h"
#include "../templates/clist_tplit.h"

/** Usage
 *    dgraph_int_t g;
 *    dgraph_add_vertex(0);
 *    dgraph_add_vertex(1);
 *    dgraph_add_edge(0, 1);
 */
// https://en.wikipedia.org/wiki/Graph_(abstract_data_type)


typedef struct connection connection;
typedef struct graph_node graph_node;

struct graph_node {
	int v;
};

LL_DEF(str)
LL_PRINT_PROTO(str);
LL_CMP_VALUE_PROTO(str);
LL_APPEND_PROTO(str);
LL_PREPEND_PROTO(str);
LL_DELETE_PROTO(str);
LL_CONTAINS_PROTO(str);

/*
 * Setup supporting hash table
 */
#define BUCKET_COUNT 10
HT_DEF(str, node, const char*, graph_node);
HT_PUT_PROTO(str, node, const char*, graph_node);
HT_CONTAINS_KEY_PROTO(str, node, const char*, graph_node);
HT_CONTAINS_VALUE_PROTO(str, node, const char*, graph_node);
HT_REMOVE_KEY_PROTO(str, node, const char*, graph_node);
HT_GET_PROTO(str, node, const char*, graph_node);
HT_GET_PTR_PROTO(str, node, const char*, graph_node);
HT_HASH_PROTO(str, node, const char*, graph_node);
HT_FREE_PROTO(str, node, const char*, graph_node);
HT_CMP_KEY_PROTO(str, node, const char*, graph_node);
HT_CMP_VALUE_PROTO(str, node, const char*, graph_node);

#include <stddef.h>

typedef struct dgraph_t {
	ht_str_node node_hash;
} dgraph_t;

void dgraph_add_vertex   (dgraph_t*, const char*, int);
void dgraph_remove_vertex(dgraph_t*, const char*);
void dgraph_add_edge     (dgraph_t*, const char*, const char*);
void dgraph_remove_edge  (dgraph_t*, const char*, const char*);
int  dgraph_get_vertex   (dgraph_t*, const char*);

#endif
