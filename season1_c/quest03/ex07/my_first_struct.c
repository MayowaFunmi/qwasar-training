#include <stdio.h>
#include <string.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY

typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


void my_first_struct(integer_array* param_1)
{
    // get array size
    //int array_size = sizeof(param_1);
    //int int_size = sizeof(param_1[0]);
    //int size = array_size / int_size;
    printf("%d\n", param_1->size);
    int length = param_1-> size;
    for (int i=0; i<length; i++) {
        printf("%d\n", param_1->array[i]);
    }
}