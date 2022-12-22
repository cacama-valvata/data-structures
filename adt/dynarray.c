#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#include "inc/dynarray.h"


void da_print (struct array* out)
{
    errno = 0;

    printf ("{");

    for (int i = 0; i < out->size; i++)
    {
        printf ("%d", out->arr[i]);
        if (i != out->size - 1)
            printf (", ");
    }

    printf ("}\n");
}

struct array* da_create (int capacity)
{
    errno = 0;
    
    if (capacity <= 0)
        capacity = 4;

    int* data = (int*) calloc (capacity, sizeof (int));

    if (! data) // errno already set by calloc
        return NULL;

    struct array* out = (struct array*) calloc (1, sizeof (struct array*));

    if (! out) // errno already set by calloc
        return NULL;

    out->arr = data;
    out->size = 0;
    out->capacity = capacity;

    return out;
}

void da_upsize (struct array* out)
{
    errno = 0;

    if ( (out->size + 1) <= out->capacity )  // succeed ("fail") silently
        return;

    int* new_alloc = (int*) realloc (out->arr, (out->capacity) * 2);
    
    if (! new_alloc)  // errno already set by realloc
        return;

    out->arr = new_alloc;
    out->capacity *= 2;
}

int* da_get (struct array* out, int index)
{
    errno = 0;

    if (index < 0 || index > out->size)
    {
        errno = EINVAL;
        return NULL;
    }

    return &(out->arr[index]);
}

void da_set (struct array* out, int index, int value)
{
    errno = 0;

    if (index < 0 || index > out->size)
    {
        errno = EINVAL;
        return;
    }

    out->arr[index] = value;
}

void da_insert (struct array* out, int index, int value)
{
    errno = 0;

    if (index < 0 || index > out->size)
    {
        errno = EINVAL;
        return;
    }

    da_upsize (out);
    if (errno != 0)
        return;

    out->size += 1;
    for (int i = out->size; i > index; i--)
    {
        out->arr[i] = out->arr[i-1];
        out->arr[i-1] = 0;
    }
    out->arr[index] = value;
}

void da_remove (struct array* out, int index)
{
    errno = 0;

    if (index < 0 || index >= out->size)
    {
        errno = EINVAL;
        return;
    }

    out->size -= 1;
    for (int i = index; i < out->size; i++)
    {
        out->arr[i] = out->arr[i+1];
        out->arr[i+1] = 0;
    }
    out->arr[out->size] = 0;
}

void da_destroy (struct array** out)
{
    free ( (*out)->arr );
    free ( (*out) );
}
