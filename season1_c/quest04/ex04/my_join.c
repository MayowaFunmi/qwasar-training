#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif


char* my_join(string_array* param_1, char* param_2){
    char temp_arr[200] = {""};
    int c = 0;
    char* param_mem = (char*)malloc(sizeof(char)*500);
    for (int i = 0; i < param_1->size; i++) {
        // add each string of the array to a new array, character by character
        for(int j = 0; j<strlen(param_1->array[i]); j++) {
            temp_arr[c] = param_1->array[i][j];
            c ++;
        }
        // add the delimiter to the end of each string
        if (i < param_1->size-1) {
            for (int x = 0; x < strlen(param_2); x++) {
                temp_arr[c] = param_2[x];
                c++;
            }
        }
    }
    sprintf(param_mem, "%s", temp_arr);
    if(temp_arr[0] == '\0') {
        return NULL;
    } else {
        return param_mem;
    }
}