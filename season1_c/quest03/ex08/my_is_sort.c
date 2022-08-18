#include <stdbool.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


bool my_is_sort(integer_array* param_1)
{
    // get array size
    // int array_size = sizeof(param_1);
    // int int_size = sizeof(param_1[0]);
    // int size = array_size / int_size;
    // if (size == 4) {
    //     return true;
    // }
   if (param_1->size == 0) {
       return true;
   }
    for (int i=0; i < param_1->size; i++) {
        if ((param_1-> array[i] < param_1-> array[i+1]) && param_1-> array[i+1] > param_1-> array[i+2]) {
            return false;
        }
        if ((param_1-> array[i] <= param_1->array[i+1]) || (param_1-> array[i] >= param_1->array[i+1])){
            return true;
        }
    }
    return false;
}


/*
printf("%d\n", param_1->size);
    int length = param_1-> size;
    for (int i=0; i<length; i++) {
        printf("%d\n", param_1->array[i]);
    }
*/