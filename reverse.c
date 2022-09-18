#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse_string(char* param_1){
    char new_string[50];
    //new_string = malloc(50);
    int x = 0;
    for (int i=strlen(param_1); i>=0; i--) {
        new_string[x] = param_1[i];
        x ++;
    }
    printf("%s", new_string);
    //return new_string;
}

int main() {
    char my_str[] = "Hello";
    printf("Before reverse -> %s", my_str);
    printf("Reverse -> %s", reverse_string(my_str));
    return 0;
}