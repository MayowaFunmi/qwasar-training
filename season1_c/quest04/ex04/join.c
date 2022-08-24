#include <stdio.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array{
    int size;
    char** array;
} string_array;
#endif
char* my_join(string_array* param_a, char* param_b){
    char term[100] = {""};
    int z = 0;
    char* mem = (char*)malloc(sizeof(char)*500);    
    for(int x=0; x<param_a->size; x++){            
        for(int y=0; y<strlen(param_a->array[x]); y++){     
            term[z]=param_a->array[x][y];        // add each letter of each string in the array to term array  
            z++;                                    
        }
        if(x<param_a->size-1){                      
            for(int a=0; a<strlen(param_b); a++){   
                term[z] = param_b[a];               
                z++;                                
            }
        }
    }sprintf(mem, "%s", term);      
    if(term[0] == '\0'){           
        return NULL;    
    }else{
    return mem;                     
    }
}