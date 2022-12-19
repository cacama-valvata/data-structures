//#include <stdio.h>
#include "dynarray.h"

void print_step_array (struct array* arr)
{
    printf ("Array: ");
    print_array (arr);
    printf ("Size: %d\n", arr->size);
    printf ("Capacity: %d\n", arr->capacity);

    printf("====================================\n");
}

void test_dynarray ()
{
    // Creation of array
    struct array* arr = create_array (2);

    // Print empty array
    print_step_array (arr);

    // Insert element at start of empty array 
    insert_element (arr, 0, 5);
    print_step_array (arr);

    // Insert element at start of populated array
    insert_element (arr, 0, 1);
    print_step_array (arr);

    // Insert element at end of populated array
    insert_element (arr, 2, 4);
    print_step_array (arr);

    // Insert element in middle of populated array
    insert_element (arr, 2, 0);
    print_step_array (arr);

    // Get a previously inserted element
    int emt = *(get_element (arr, 2));
    printf ("Element: %d\n", emt);
    printf("====================================\n");

    // Set a previously inserted element
    set_element (arr, 0, 6);
    print_step_array (arr);

    // Remove a previously inserted element
    remove_element (arr, 0);
    print_step_array (arr);

    // Destroy the array
    destroy_array (&arr);
}

int main ()
{
    test_dynarray ();

    return 0;
}