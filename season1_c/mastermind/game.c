#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STRINGS 4

int random_num() {
    int num = rand() % 8;
    char val = num +'0';
    return val;
}


int main(int argc, char* argv[]) {
    char temp;
    time_t t1;
    char secret_code[NUM_STRINGS];
    srand((unsigned) time(&t1));
    for(int i=0; i<NUM_STRINGS; i++) {
        temp = random_num();
        secret_code[i] = temp;
    }

    //printf("%s\n", secret_code);
    char* secret = "0123";
    printf("secret = %s\n", secret);

    printf("\n");

    // get code from user
    char* get_code;
    get_code = argv[1];
    // for(int x =1; x<argc; x++) {
    //     get_code = argv[x];
    // }
    printf("get code = %s\n", get_code);

    printf("Will you find the secret code?\n");

    int i = 0;
    int well_placed = 0;
    int misplaced = 0;
    // check for membership
    for (int x=0; x<strlen(get_code); x++) {
        for (int y=0; y<strlen(secret); y++) {
            // check if element from get_code is in element from secret
            if((x == y) && (get_code[x] == secret[y])) {
                well_placed ++;
                // check if they are in the same index
            } else if((x != y) && (get_code[x] == secret[y])) {
                misplaced ++;
            }
        }
    }
    printf("Well placed pieces: %d\n", well_placed);
    printf("Misplaced pieces: %d\n", misplaced);
}