#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

struct array
{
    int* arr;
    int size;
    int capacity;
};


int print_array (struct array* out)
{
    printf ("{");

    for (int i = 0; i < out->size; i++)
    {
        printf ("%d", out->arr[i]);
        if (i != out->size - 1)
            printf (", ");
    }

    printf ("}\n");
}

int create_array (struct array** out, int capacity)
{
    if (! out)
    {
        out = NULL;
        return EINVAL;
    }

    if (capacity <= 0)
        capacity = 4;

    int* data = (int*) calloc (capacity, sizeof (int));

    if (! data)
    {
        out = NULL;
        return ENOMEM;
    }

    (*out) = (struct array*) calloc (1, sizeof (struct array*));
    (*out)->arr = data;
    (*out)->size = 0;
    (*out)->capacity = capacity;

    return 0;
}

int upsize_array (struct array* out)
{
    if ( (out->size + 1) <= out->capacity )
        return 0;

    int* new_alloc = (int*) realloc (out->arr, (out->capacity) * 2);
    
    if (! new_alloc)
        return ENOMEM;

    out->arr = new_alloc;
    out->capacity *= 2;

    return 0;
}

int get_element (struct array* out, int* value, int index)
{
    if (index < 0 || index > out->size || ! value)
        return EINVAL;

    *value = out->arr[index];
    
    return 0;
}

int set_element (struct array* out, int index, int value)
{
    if (index < 0 || index > out->size)
        return EINVAL;

    out->arr[index] = value;
    return 0;
}

int insert_element (struct array* out, int index, int value)
{
    if (index < 0 || index > out->size)
        return EINVAL;

    int r = upsize_array (out);
    if (r != 0)
        return r;

    out->size += 1;
    for (int i = out->size; i > index; i--)
    {
        out->arr[i] = out->arr[i-1];
        out->arr[i-1] = 0;
    }
    out->arr[index] = value;

    return 0;
}

int remove_element (struct array* out, int index)
{
    if (index < 0 || index >= out->size)
        return EINVAL;

    out->size -= 1;
    for (int i = index; i < out->size; i++)
    {
        out->arr[i] = out->arr[i+1];
        out->arr[i+1] = 0;
    }
    out->arr[out->size] = 0;

    return 0;
}

int destroy_array (struct array** out)
{
    free ( (*out)->arr );
    free ( (*out) );

    return 0;
}
