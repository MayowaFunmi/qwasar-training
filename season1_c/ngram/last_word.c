#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* last_word(char* param_1){
    char length = strlen(param_1);
    int i;
    int count = 0;
    int y = 0;
    char* last;
    last = malloc(100);

    if (param_1[length-1] == ' ') {
        i = length-2;
    } else if (param_1[length-2] == ' ') {
        i = length-3;
    } else {
        i = length-1;
    }
    printf("i = %d\n", i);
    printf("length = %d\n", length);

    for (i; i>0; i--) {
        //printf("%c", param_1[length-1]);
        if (param_1[i]== ' ' || param_1[i] == ',') {
            count = i;
            break;
        }
    }
    printf("count = %d\n", count);

    //
    for (int x=count+1; x<length; x++) {
        //printf("%c", param_1[x]);
        last[y] = param_1[x];
        y++;
    }
    return last;
}

int main() {
    char* str;
    str = malloc(100);
    str = "  lorem,ipsum  ";
    printf("%s\n", last_word(str));
}