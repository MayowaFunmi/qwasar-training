#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {
    FILE* fptr;
    fptr = fopen(argv[2], "r");
    if(!fptr || argc != 2) {
        printf("ERROR");
    }

    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(fptr);
}