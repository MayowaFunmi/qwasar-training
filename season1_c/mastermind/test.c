#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int num[4], lower = 1, upper = 90, count = 4;
    for (int j=0; j<4; j++) { 
        num[j] = 0;
    }
    for (int i=0; i< count; i++) {
        num[i] = (rand() % (upper - lower + 1)) + lower;
    }
    printf("number = %d\n", num);
}

