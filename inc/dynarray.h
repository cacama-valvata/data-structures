/* Dynamic Array ADT */

struct array
{
    int* arr;
    int size;
    int capacity;
};


void da_print (struct array* out);

struct array* da_create (int capacity);

void da_upsize (struct array* out);

int* da_get (struct array* out, int index);

void da_set (struct array* out, int index, int value);

void da_insert (struct array* out, int index, int value);

void da_remove (struct array* out, int index);

void da_destroy (struct array** out);
