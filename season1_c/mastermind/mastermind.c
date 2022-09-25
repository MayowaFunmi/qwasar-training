#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "info.h"

#define NUM_STRING 4

int main(int argc, char* argv[]) {
    char* secret = argv[1];
    //printf("secret = %s\n", secret);
    start_info();

    int i=0;
    while (i<10){
        int well_placed = 0;
        int misplaced = 0;
        printf("Round %d\n", i);
        char* get_code = commandInput();
        //printf("get code = %s\n", get_code);

        // check for digits
        if((my_isdigit(get_code) == 0) && (equality(get_code, secret) == 0)) {
            printf("Congratz! You did it!\n");
            break;
        } else if((my_isdigit(get_code) == 0) && (equality(get_code, secret) != 0)) {
            // check for membership
            for (int x=0; x<strlen(get_code); x++) {
                for (int y=0; y<strlen(secret); y++) {
                    // check if element from get code is in element from secret
                    if ((x == y) && (get_code[x] == secret[y])) {
                        well_placed ++;
                        // check if they are in the same index
                    } else if ((x != y) && (get_code[x] == secret[y])) {
                        misplaced ++;
                    }
                }
            }
            i++;
            printf("Well placed pieces: %d\n", well_placed);
            printf("Mislaced pieces: %d\n", misplaced);
            printf("\n");
        } else {
            printf("Wrong input!\n");
            continue;;
        }
    }
    //gcc my_mastermind.c -o my_mastermind
    // gcc -c my_mastermind.c => creates my_mastermind.o
    // gcc -o my_mastermind my_mastermind.o => creates my_mastermind file

    /*
    // check for membership
            int x = 0, y = 0;
            while (get_code[x] != '\0') {
                while (secret[y] != '\0') {
                    if ((x == y) && (get_code[x] == secret[y])) {
                        well_placed ++;
                        // check if they are in the same index
                    } else if ((x != y) && (get_code[x] == secret[y])) {
                        misplaced ++;
                    }
                    y++;
                }
                x++;
            }
    */
}