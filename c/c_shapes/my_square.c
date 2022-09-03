#include <stdio.h>
# include <stdlib.h>

void my_square(int col, int row) {
    for (int i = 1; i <= row; i++) {
        //printf("\n");
        for (int j=1; j <= col; j++) {
            if ((i==1 && j==1) || (i==1 && j==col) || (i==row && j==1) || (i==row && j==col)) {
                printf("o");
            }
            if ((j>1 && j<col) && (((i==1 && j>1) || (i==1 && j<col)) || (i==row && j>1) || (i==row && j<col))) {       // ((1<i<row) && (j==1 || j==col))
                printf("-");
            }
            
            if ((i>1 && i<row && j==1) || (i>1 && i<row && j==col)) {
                printf("|");
            } else if ((i>1 && i<row && j>1) || (i>1 && i<row && j<col)) {
                printf(" ");
            }
        }
        printf("\n");
    }
    //printf("\n");
}

int main (int ac, char **av) {
    int x, y;
    printf("%d\n", ac);
    if (ac == 2) {
        x = atoi(av[1]);
        y = 0;
        printf(" ");
    } else if (ac == 3){
        x = atoi(av[1]);
        y = atoi(av[2]);
        my_square(x, y);
    }
}