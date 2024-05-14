#include "munit.h"
#include "../examples/ht_str_int.h"
#include <stdbool.h>

MunitResult chash_str_int(const MunitParameter params[], void* userdata) {
	ht_str_int ht = {0};
	ht_str_int_put(&ht, "value", 5);
	ht_str_int_put(&ht, "value2", 15);
	munit_assert_true(ht_str_int_contains_key(&ht, "value2"));
	munit_assert_int(ht_str_int_get(&ht, "value2"), ==, 15);
	munit_assert_true(ht_str_int_contains_value(&ht, 5));
	munit_assert_true(ht_str_int_contains_value(&ht, 15));
	ht_str_int_free(&ht);
	return MUNIT_OK;
}


static const MunitTest chash[] = {
	{ "/str_int", chash_str_int, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
	"/chash_tplt", chash, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char** argv) {
	return munit_suite_main(&suite, NULL, argc, argv);
}
