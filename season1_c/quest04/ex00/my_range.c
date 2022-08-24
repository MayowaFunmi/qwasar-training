#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* my_range(int min, int max) {
    int* arr;
    arr = (int*)malloc(sizeof(int) *max-min);
    if (min >= max) {
        return 0;
    }
    for (int i=0; i < max-min; i++) {
        arr[i] = min + i;
    }
    return arr;
    //printf("%d", *arr[5]);
}