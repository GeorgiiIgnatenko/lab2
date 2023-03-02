#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
int main()
{
    IntVector *array = int_vector_new(3);
	  printf("IntVector array \n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    for (int i = 0; i < array->capacity; i++)
    {
        array -> data[i] = i;
        array -> size++;
        printf("%d\n",array -> data[i]);
    }
    printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    IntVector *a = int_vector_copy(array);
	  printf("Vector a = data:%p\n",a->data);
	  for (int i = 0; i < array->capacity; i++) {
		  printf("%d\n", a->data[i]);
    }
    printf("IntVector a\n data = %p\n size = %ld\n capacity = %ld\n", a->data, a->size, a->capacity);
    printf("\n");
    printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    int_vector_set_item(array,2,7);
    for (int i = 0; i < array->capacity; i++) {
		  printf("%d\n", array->data[i]);
    }
    printf("\n");
    int_vector_push_back(array,10);
    for (int i = 0; i < array->size; i++) {
		  printf("%d\n", array->data[i]);
    }
    printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    printf("\n");
    printf("gb\n");
    int_vector_pop_back(array);
    printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    for (int i = 0; i < array->size; i++) 
    {
		  printf("%d\n", array->data[i]);
    }
      int_vector_shrink_to_fit(array);
      printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    for (int i = 0; i < array->size; i++) 
    {
		  printf("%d\n", array->data[i]);
    }
    int_vector_resize(array,10);
    printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    for (int i = 0; i < array->size; i++) 
    {
		  printf("%d\n", array->data[i]);
    }
    int_vector_reserve(array,40);
    printf("IntVector array\n data = %p\n size = %ld\n capacity = %ld\n", array->data, array->size, array->capacity);
    for (int i = 0; i < array->size; i++) 
    {
		  printf("%d\n", array->data[i]);
    }
    return 0;
}
