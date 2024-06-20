#define JOIN2(a, b) a ## b
#define JOIN3(a, b, c) a ## b ## c
#define JOIN4(a, b, c, d) a ## b ## c ## d
#define JOIN5(a, b, c, d, e) a ## b ## c ## d ## e

#define RBTREE_MAIN_STRUCT_NAME(value_name) JOIN2(rb_, value_name)
#define RBTREE_NODE_STRUCT_NAME(value_name) JOIN3(rb_, value_name, _node)

#define RBTREE_NODE_DEF(value_name)\
typedef struct RBTREE_NODE_STRUCT_NAME(value_name) {\
	value_name val;\
	int color;\
	RBTREE_NODE_STRUCT_NAME(value_name) *left, *right;\
} RBTREE_NODE_STRUCT_NAME(value_name);

#define RBTREE_DEF(value_name)\
typedef struct RBTREE_MAIN_STRUCT_NAME(value_name) {\
	RBTREE_NODE_STRUCT_NAME(value_name) *root;\
	int size;\
} RBTREE_MAIN_STRUCT_NAME(value_name);

#define RBTREE_PUT_PROTO(value_name)\
	void JOIN3(rb_, value_name, put)(RBTREE_MAIN_STRUCT_NAME(value_name)*, value_name)

#define RBTREE_CONTAINS_PROTO
