#include<stdio.h>

int main() {
    int i, j, Side;

    printf("Provide how long should a side should be e.g 4: \n");
    scanf("%d", &Side);

    for(i = 0; i < Side; i++) {
        for(j = 0; j < Side; j++)
        {
            printf("*");
        }

        // Add a new row
        printf("\n");
    }

    return 0;
}
