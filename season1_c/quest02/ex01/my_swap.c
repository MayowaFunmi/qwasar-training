#include <stdio.h>

void my_swap(int* param_1, int* param_2) {
    int x;
    x = *param_1; // save value 1 in x
    *param_1 = *param_2; // change val 1 to val 2
    *param_2 = x;
}

int main() {
    int variable_a = 12;
    int variable_b = 21;

    printf("A - %d ** B - %d\n", variable_a, variable_b);
    my_swap(&variable_a, &variable_b);
    printf("A - %d ** B - %d\n", variable_a, variable_b);
    return 0;
}