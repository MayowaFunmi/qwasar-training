#include<stdio.h>

int main() {
    int i, j, Side;
    int row = 3;
    int col = 5;
    printf("Provide how long should a side should be e.g 4: \n");
    //scanf("%d", &Side);

    for(i = 0; i < row; i++) {
    	printf("o");
      for(j = 1; j < col; j++) {
        printf("-");
      }

        // Add a new row
      printf("\n");
    }

    return 0;
}
