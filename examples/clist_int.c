#include "clist_int.h"

LL_CMP_VALUE_IMPL(int) {
	return val1 == val2;
}
LL_APPEND_IMPL(int);
LL_PREPEND_IMPL(int);
LL_DELETE_IMPL(int);
LL_CONTAINS_IMPL(int);
