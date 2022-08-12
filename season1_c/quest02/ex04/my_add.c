#include <stdio.h>

int my_add(int param_1, int param_2) {
    int sum;
    sum = param_1 + param_2;
    //return sum;
    printf("%d + %d = %d", param_1, param_2, sum);
    return 0;
}


int main() {
    int nbr1, nbr2, sum;
    scanf("%d %d", &nbr1, &nbr2);
    my_add(nbr1, nbr2);
}