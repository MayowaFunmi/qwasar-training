#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h> 
void arrange (char array[], int size) {

for (int step = 0; step < size - 1; ++size ) {

for (int i = 0; i < size - step - 1; ++i){

if (array[i] > array[i + 1]) {
int temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp; } }
}
}
int main(int a, char*av) {
    charjoin;
    join=(malloc(700sizeof(char)));

    int counter = 0;
    for (int i =1; i < a; i++) {
        charcurrent_str=av[i];

        int length = strlen(current_str);
        for (int j = 0; j <length; j++){
            join[counter] = current_str[j];
            counter++;
        }
    }
    int str_len = strlen(join);

    arrange(join, str_len);
    char unique[str_len];

    int counted = 0;

    for(int i = 0; i < str_len; i++) {
        bool char_counted = false;
        for (int j = 0; j < counted; j++){
            if(join[i] == unique[j]){
                char_counted = true;
                continue;
            }
        }
        if(char_counted){
            continue;
        }
        int counter = 0;
        for (int j = 0; j < str_len; j++){
            if (join[i] == join[j]) counter++;
        }
        printf("%c:%d/n", join[i], counter);
        unique[counted] = join[i];
        counted++;
    }
    return EXIT_SUCCESS;
}