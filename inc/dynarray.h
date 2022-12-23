/* Dynamic Array ADT */

typedef struct array
{
    int* arr;
    int size;
    int capacity;
} array;


void da_print (array* out);

array* da_create (int capacity);

void da_upsize (array* out);

int* da_get (array* out, int index);

void da_set (array* out, int index, int value);

void da_insert (array* out, int index, int value);

void da_remove (array* out, int index);

void da_destroy (array** out);
