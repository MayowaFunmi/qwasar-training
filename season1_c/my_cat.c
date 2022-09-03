#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {
    FILE* ptr;
    char file;
    for (int i=1; i<argc; i++) {
        printf("%s\n", argv[i]);
        ptr = fopen(argv[i], "r");
        while ((file = getc(ptr)) != EOF) {
            printf("%c", file);
        }
        printf("\n");
    }
    fclose(ptr);

    /*
    FILE* ptr;
    ptr = fopen(argv[1], "r");
    char file;
    while ((file = fgetc(ptr)) != EOF) {
        printf("%c", file);
    }
    fclose(ptr);
    */
}