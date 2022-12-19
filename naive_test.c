#include <stdio.h>

#include "adt/dynarray.h"

void print_step_array (struct array* arr)
{
    printf ("Array: ");
    da_print (arr);
    printf ("Size: %d\n", arr->size);
    printf ("Capacity: %d\n", arr->capacity);

    printf("====================================\n");
}

void test_dynarray ()
{
    // Creation of array
    struct array* arr = da_create (2);

    // Print empty array
    print_step_array (arr);

    // Insert element at start of empty array 
    da_insert (arr, 0, 5);
    print_step_array (arr);

    // Insert element at start of populated array
    da_insert (arr, 0, 1);
    print_step_array (arr);

    // Insert element at end of populated array
    da_insert (arr, 2, 4);
    print_step_array (arr);

    // Insert element in middle of populated array
    da_insert (arr, 2, 0);
    print_step_array (arr);

    // Get a previously inserted element
    int emt = *(da_get (arr, 2));
    printf ("Element: %d\n", emt);
    printf("====================================\n");

    // Set a previously inserted element
    da_set (arr, 0, 6);
    print_step_array (arr);

    // Remove a previously inserted element
    da_remove (arr, 0);
    print_step_array (arr);

    // Destroy the array
    da_destroy (&arr);
}

int main ()
{
    test_dynarray ();

    return 0;
}