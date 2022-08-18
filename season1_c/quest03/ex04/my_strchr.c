#include <stdio.h>
#include <string.h>

char* my_strchr(char* param_1, char param_2) {
    int count = 0;
    int location = 0;
    for (int i=0; i <= strlen(param_1); i++) {
        if (param_1[i] == param_2) {
            location = i;
            break;
        }
    }
    

    int counter = 0;
    char *new_str;
    if (location == 0) {
        return NULL;
    } else {
        for (int i = location; i < strlen(param_1); i++) {
            new_str[counter] = param_1[i];
            counter ++;
        }
    }
    return new_str;
}


int main() {
  char str[1000], c;
  str[1000] = "abcdbe";
  c = "b";
  
  printf("my_strchr -> %s\n", my_strchr(str, c));
  return 0;
}


/*

char* my_strrchr(char* param_a, char param_b){
    char* swap = NULL;
    for(;;){
        if (*param_a == param_b)
            swap = param_a;
        if (*param_a++ == '\0')
            return swap;
        }
}
*/