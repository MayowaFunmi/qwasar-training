#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#define NUM_STRING 4

char* commandInput() {
    char* save = (char*)malloc(5*sizeof(char));
    save[5] = '\0';
    fflush(stdout);
    read(0, save, 5);
    return save;
}

int equality(char* param1, char*param2) {
    int i = 0;
    while (param1[i] != '\0') {
        if (param1[i] == param2[i]) {
            return 0;
        } else {
            return 1;
        }
    }
}

int random_num() {
    int num = rand() % 8;
    char val = num + '0';
    return val;
}

int my_isdigit(char* param_1) {
    int count = 0;
    for(int i=0; i<strlen(param_1); i++) {
        if (isdigit(param_1[i])) {
            return 0;
        }
    }
    //printf("count = %d\n", count);
    return 1;
}

int main(int argc, char* argv[]) {
    char* secret = argv[2];
    printf("secret = %s\n", secret);
    // printf("\n");

    // get code from user
    // char* get_code;
    // get_code = argv[1];

    // printf("get code = %s\n", get_code);
    // char temp;
    // time_t t1;
    // char secret[NUM_STRING];
    // srand((unsigned) time(&t1));
    // for(int k=0; k<NUM_STRING; k++) {
    //     temp = random_num();
    //     secret[k] = temp;
    // }
    printf("Will you find the secret code?\n");

    int i=0;
    while (i<10){
        int well_placed = 0;
        int misplaced = 0;
        printf("Round %d\n", i);
        char* get_code = commandInput();
        printf("get code = %s\n", get_code);

        // if (equality(get_code, secret) == 0) {
        //     printf("Congratz\n");
        // } else {
        //     printf("Try again\n");
        // }
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
}