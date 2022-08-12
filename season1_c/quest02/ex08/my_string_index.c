#include <stdio.h>

int my_string_index(char* param_1, char param_2) {
    int index = 0;
    while (*param_1 != '\0') {
        if (*param_1 == param_2) {
            //printf("%d\n", index);
            return index;
        }
        index ++;
        param_1 ++;
    }
    return -1;
}
