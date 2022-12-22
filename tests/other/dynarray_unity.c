#include "adt/dynarray.h"
#include "Unity/src/unity.h"


void setUp () {}

void tearDown () {}


void test_da_create_0 ()
{
    struct array* arr = da_create (0);
}

void test_da_create_5 ()
{
    struct array* arr = da_create (5);
}

void test_da_insert ()
{
    struct array* arr = da_create (0);

    da_insert (arr, 0, 4);

    TEST_ASSERT_EQUAL_INT (*(da_get (arr, 0)), 4);

    da_destroy (&arr);
}


int main ()
{
    UNITY_BEGIN ();

    RUN_TEST (test_da_create_0);
    RUN_TEST (test_da_create_5);
    RUN_TEST (test_da_insert);

    return UNITY_END ();
}