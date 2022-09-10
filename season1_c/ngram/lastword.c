#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* lastword(char* param) {
    char length = strlen(param);
    int i;
    int count = 0;
    for (i=length-1; i>0; i--) {
        if(param[i] == ' ') {
            count = i;
            //printf("%d\n", i);
            break;
        }
    }

    for (int x=count; x<length; x++) {
        printf("%c", param[x]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    char* str;
    str = malloc(100);
    str = argv[1]; "//testing if this works";

    lastword(str);

}