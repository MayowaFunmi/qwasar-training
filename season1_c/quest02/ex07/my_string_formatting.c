#include <stdio.h>

void my_string_formatting(char* param_1, char* param_2, int param_3) {
    printf("%s\n", param_1);
    printf("Hello, my name is %s %s, I'm %d\n", param_1, param_2, param_3);
}


int main() {
    char* first;
    char* last;
    first = "Mayowa";
    last = "Akinade";
    int age = 35;
    printf("%s\n", first);
    my_string_formatting(first, last, age);
}