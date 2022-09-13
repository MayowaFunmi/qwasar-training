#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* alpha_mirror(char* param_1) {
    char* new;
    new = malloc(100);
    for (int i=0; i<strlen(param_1); i++) {
        new[i] = param_1[i] - 97;
    }

    printf("%d", *new);
}


int main(int argc, char* argv[]) {
    char* str;
    str = malloc(100);
    str = argv[1];
    alpha_mirror(str);
}