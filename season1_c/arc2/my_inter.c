#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int duplicate(char* str, char letter) {
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == letter){
            return 1;
            break;
        }
    }
    return 0;
}
char* my_union(char* param_1, char* param_2) {
    //printf("%s\n", param_2);
    char* str;
    str = malloc(50);
    int k = 0;
    for (int i = 0; i < strlen(param_1); i++){
        for (int j = 0; j < strlen(param_2); j++){
            if (param_1[i] == param_2[j]){
                if ((duplicate(str, param_1[i])) == 0){
                    //printf("%c\n", param_1[i]);
                    str[k] = param_1[i];
                    k++;
                }
            }
            
        }
        
    }
    return str;
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        char* param_1 = argv[1];
        char* param_2 = argv[2];
        printf("%s\n", my_union(param_1, param_2));
    }
}