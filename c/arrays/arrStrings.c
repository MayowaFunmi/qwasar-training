#include <stdio.h>

int main() {
    char* arr[] = {"This", "is", "my", "project"};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%p\n", &arr);   // returns the pointer
    printf("%s\n", *arr);   // returns first string
    printf("%d\n", size);

    for (int i=0; i<size; i++) {
        printf("%s", arr[i]);
        printf(" ");
    }
    printf("\n");
}