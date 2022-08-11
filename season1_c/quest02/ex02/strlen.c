#include <stdio.h>
#include <string.h>

void my_strlen(const char* param) {
    int length = 0;
    if (param != NULL) {
        while (*param != '\0'){
            length ++;
            param ++;
        }
    }
    printf("%d\n", length);
}

int main() {
    char* str;
    str = "working fine";
    int length;
    my_strlen(str);
    //printf("%s %d\n", str, length);
    return 0;
}