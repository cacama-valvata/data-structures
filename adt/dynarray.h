#include <stdlib.h>
#include <errno.h>

struct array
{
    int* arr;
    int size;
    int capacity;
};


int create (struct array** out, int capacity)
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

int upsize (struct array* out)
{
    if ( (out->size + 1) < out->capacity )
        return 0;

    int* new_alloc = (int*) realloc (out->arr, (out->capacity) * 2);
    
    if (! new_alloc)
        return ENOMEM;

    out->arr = new_alloc;
    out->capacity *= 2;

    return 0;
}

int get (struct array* out, int* value, int index)
{
    if (index < 0 || index > out->size || ! value)
        return EINVAL;

    *value = out->arr[index];
    
    return 0;
}

int set (struct array* out, int index, int value)
{
    if (index < 0 || index > out->size)
        return EINVAL;

    out->arr[index] = value;
    return 0;
}

int insert (struct array* out, int index, int value)
{
    if (index < 0 || index > out->size)
        return EINVAL;

    int r = upsize (out);
    if (r != 0)
        return r;

    out->size += 1;
    for (int i = out->size; i > index; i++)
    {
        out->arr[i] = out->arr[i-1];
        out->arr[i-1] = 0;
    }
    out->arr[index] = value;

    return 0;
}

int remove (struct array* out, int index)
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

int destroy (struct array** out)
{
    free ( (*out)->arr );
    free (out);

    return 0;
}
