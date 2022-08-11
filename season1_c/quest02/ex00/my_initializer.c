#include <stdio.h>

void my_initializer(int* param_1) { //param_1 is the address of a variable
    *param_1 = 0;   // change the value of variable to 0
}

int main() {
    int variable_a = 12;

    printf("%d\n", variable_a);
    my_initializer(&variable_a);
    printf("%d\n", variable_a);
    return 0;
}