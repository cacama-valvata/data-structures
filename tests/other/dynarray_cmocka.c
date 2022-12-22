#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

#include "adt/dynarray.h"


static int setup (void** state)
{
    struct array* arr = da_create (0);
    *state = arr;

    return 0;
}

static int teardown (void** state)
{
    struct array* arr = *state;
    da_destroy (&arr);

    return 0;
}


static void test_da_create_0 ()
{
    struct array* arr = da_create (0);

    assert_int_equal (arr->size, 0);
    assert_int_equal (arr->capacity, 4);
    assert_non_null (arr->arr);

    da_destroy (&arr);
}

static void test_da_create_5 ()
{
    struct  array* arr = da_create (5);

    assert_int_equal (arr->size, 0);
    assert_int_equal (arr->capacity, 5);
    assert_non_null (arr->arr);

    da_destroy (&arr);
}

static void test_da_insert (void** state)
{
    struct array* arr = da_create (0);

    da_insert (arr, 0, 5);

    assert_int_equal (*(da_get (arr, 0)), 5);

    da_destroy (&arr);
}


int main ()
{
    const struct CMUnitTest create_tests[] = {
        cmocka_unit_test (test_da_create_0),
        cmocka_unit_test (test_da_create_5)
    };

    const struct CMUnitTest insert_tests[] = {
        cmocka_unit_test (test_da_insert)
    };

    cmocka_run_group_tests (create_tests, NULL, NULL);
    cmocka_run_group_tests (insert_tests, setup, teardown);

    return 0;
}