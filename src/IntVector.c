#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *v = NULL;
    v = malloc(sizeof(*v));
    if (!v)
    {
        return NULL;
    }
    v->data = malloc(initial_capacity*sizeof(int));
    if (!v->data)
    {
        free(v);
        return NULL;
    }
    v->capacity = initial_capacity;
    v->size = 0;
    return v;

}
IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *z = NULL;
    z = malloc(sizeof(*z));
    if (!z)
    {
        return NULL;
    }
    z->data = malloc(v->capacity * sizeof(int));
    if (!z->data)
    {
        free(z);
        return NULL;
    }
    memcpy(z->data,v->data, sizeof(int) * v->capacity);
    z->size = v->size;
	z->capacity = v->capacity;
    return z;
}
void int_vector_free(IntVector *v)
{
    free(v->data);
    free(v);
}
int int_vector_get_item(const IntVector *v, size_t index)
{
    int s = v->data[index];
    return s;
}
void int_vector_set_item(IntVector *v, size_t index, int item)
{
    v->data[index] = item;
}
size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}
size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}
int int_vector_push_back(IntVector *v, int item)
{
    if (v->size < v->capacity)
    {
        v->data[v->size] = item;
        v->size++;
    }
    else
    {
        v->capacity = v->capacity * 2;
        int *z = realloc(v->data,v->capacity * sizeof(int));
        if (!z)
        {
            return -1;
        }
        v -> data = z;
        v -> data[v->size] = item;
        v -> size++;
    }
    return 0;
}
void int_vector_pop_back(IntVector *v)
{
    if (v->size > 0)
    {
        size_t s = v->size;
        s = s-1;
        size_t j = v->capacity;
        IntVector *z = int_vector_new(j);
        for(int i = 0; i<s; i++)
        {
            z->data[i] = v->data[i];
        }
        *v = *z;
        v->size = s;
    }
}
int int_vector_shrink_to_fit(IntVector *v)
{
    if (v->size < v->capacity)
    {
        v->capacity = v->size;
        int *z = realloc(v->data,v->size *sizeof(int));
        if (!z)
        {
            return -1;
        }
        v->data = z;
        return 0;
    }
    return -1;
}
int int_vector_resize(IntVector *v, size_t new_size)
{
    if (new_size > v->size)
    {
        int *z = realloc(v->data,new_size *sizeof(int));
        if (!z)
        {
            return -1;
        }
        v->data = z;
        for (int i = v->size; i<new_size;i++)
        {
            v->data[i] = 0;
        }
        v->size = new_size;
    }
    if (v->capacity >= v->size)
    {
        v->capacity = v->capacity;
    }
    if (v->capacity < v->size)
    {
        v->capacity = v->size;
    }
    if (v->size == new_size)
    {
        return 0;
    }
    if (new_size < v->size)
    {
        return -1;
    }   
    return 0;
}
    int int_vector_reserve(IntVector *v, size_t new_capacity)
    {
        if (new_capacity > v->capacity)
        {
            v->capacity = new_capacity;
            int *z = realloc(v->data,new_capacity*sizeof(int));
            if (!z)
            {
                return -1;
            }
            v->data = z;
            return 0;
        }
        else
        {
            return -1;
        }
    }