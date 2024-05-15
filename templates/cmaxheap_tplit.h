// ========
#define JOIN2(a, b) a ## b
#define JOIN3(a, b, c) a ## b ## c
#define JOIN4(a, b, c, d) a ## b ## c ## d
#define JOIN5(a, b, c, d, e) a ## b ## c ## d ## e

#define MAX_HEAP_MAIN_STRUCT_NAME(type_name) JOIN2(heap_max_, type_name)

#define MAX_HEAP_DEF(type_name)\
	typedef struct {\
		type_name data[CAPACITY];\
		int size;\
	} MAX_HEAP_MAIN_STRUCT_NAME(type_name)

#define MAX_HEAP_ENQUEUE_PROTO(value_type)\
	void JOIN3(heap_max_, value_type, _enqueue)(MAX_HEAP_MAIN_STRUCT_NAME(value_type)*, value_type)

#define MAX_HEAP_DEQUEUE_PROTO(value_type)\
	value_type JOIN3(heap_max_, value_type, _dequeue)(MAX_HEAP_MAIN_STRUCT_NAME(value_type)*)

#define MAX_HEAP_ENQUEUE_IMPL(value_type)\
	void JOIN3(heap_max_, value_type, _enqueue)(MAX_HEAP_MAIN_STRUCT_NAME(value_type) *heap, value_type val) {\
		int index = heap->size;\
		if (index > CAPACITY) return;\
		heap->data[index] = val;\
		heap->size++;\
		/* reheap up */\
		while (heap->data[index/2] < val) {\
			value_type t = heap->data[index / 2];\
			heap->data[index / 2] = heap->data[index];\
			heap->data[index] = t;\
			index = index / 2;\
		}\
	}

#define MAX_HEAP_DEQUEUE_IMPL(value_type, default)\
	void JOIN3(heap_max_, value_type, _reheap_down)(MAX_HEAP_MAIN_STRUCT_NAME(value_type) *heap) {\
		int index = 0;\
		while (1) {\
			int left_i  = index * 2 + 1;\
			int right_i = index * 2 + 2;\
			if ((left_i >= heap->size || heap->data[index] > heap->data[left_i]) && (right_i >= heap->size || heap->data[index] > heap->data[right_i])) {\
				break;\
			}\
			if (heap->data[left_i] > heap->data[right_i]) {\
				value_type t = heap->data[index];\
				heap->data[index] = heap->data[left_i];\
				heap->data[left_i] = t;\
				index = left_i;\
				continue;\
			}\
			if (heap->data[left_i] <= heap->data[right_i]) {\
				value_type t = heap->data[index];\
				heap->data[index] = heap->data[right_i];\
				heap->data[right_i] = t;\
				index = right_i;\
				continue;\
			}\
		}\
	}\
	value_type JOIN3(heap_max_, value_type, _dequeue)(MAX_HEAP_MAIN_STRUCT_NAME(value_type) *heap) {\
		if (heap->size == 0) return default;\
		value_type ret = heap->data[0];\
		heap->data[0] = heap->data[heap->size - 1];\
		JOIN3(heap_max_, value_type, _reheap_down)(heap);\
		heap->size--;\
		return ret;\
	}
