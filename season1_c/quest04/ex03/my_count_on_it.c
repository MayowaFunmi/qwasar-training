#include <stdio.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


integer_array *my_count_on_it(string_array *param) {
    integer_array *ptr;     //pointing to the integer struct declared above
    ptr = (integer_array *)malloc(sizeof(integer_array));
    ptr->size = param->size;        //-> is used to point in a function to a variable declared in a struct
    ptr->array = (int*)malloc(ptr->size * sizeof(int));     //memory allocation to the array pointed to
    for (int x = 0; x < param->size; x++) {     //looping through the string 
        ptr->array[x] = strlen(param->array[x]);    //pointing to the array index which is equal to the size/length of the array index
    }
    return ptr;
}