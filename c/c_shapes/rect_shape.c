#include <stdio.h>

int main() {
    int row = 4;
    int col = 4;

    for (int i = 1; i <= row; i++) {
        printf("\n");
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
    printf("\n");
    return 0;
}
