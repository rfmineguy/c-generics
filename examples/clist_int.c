#define LL_PRINT_FMT "%d"
#define LL_PRINT_ARGS n->val
#include "clist_int.h"
#include <stdio.h>
void log_info(const char* fmt, ...) {}
void log_line_begin(const char* fmt, ...) {}
void log_line_end(const char* fmt, ...) {}

LL_FREE_IMPL(int);
LL_PRINT_IMPL(int, "->")
LL_CMP_VALUE_IMPL(int) {
	return val1 == val2;
}
LL_APPEND_IMPL(int);
LL_PREPEND_IMPL(int);
LL_DELETE_IMPL(int);
LL_CONTAINS_IMPL(int);
