#include "clist_int.h"
#include <stdio.h>

LL_PRINT_IMPL(int) {
	printf("%d", val);
}
LL_CMP_VALUE_IMPL(int) {
	return val1 == val2;
}
LL_APPEND_IMPL(int);
LL_PREPEND_IMPL(int);
LL_DELETE_IMPL(int);
LL_CONTAINS_IMPL(int);
