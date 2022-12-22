#include "adt/dynarray.h"
#include "Unity/src/unity.h"


void setUp () {}

void tearDown () {}


void test_da_create_0 (int size)
{
    struct array* arr = da_create (size);
    TEST_ASSERT_EQUAL_INT (arr->capacity, size); //assert (arr->capacity == size);
    TEST_ASSERT_EQUAL_INT (arr->size, 0); // assert (arr->size == 0);
    TEST_ASSERT_NOT_NULL (arr->arr); //assert (arr->arr);
    da_destroy (&arr);

    printf("test_da_create_0 for size = %d: PASS\n", size);
}


int main ()
{
    for (int i = 1; i < 5; i++)
    {
        test_da_create_0 (i);
    }

    return 0;
}