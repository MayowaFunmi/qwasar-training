#include <stdio.h>
#include <string.h>

int my_strlen(char* param_1) {
    int length = 0;
    while (*param_1 != '\0') {
        length ++;
        param_1 ++;
    }
    printf("%d\n", length);
}

int main() {
    char* c;
    c = "working fine";
    //scanf(&c);
    my_strlen(c);
    return 0;
}