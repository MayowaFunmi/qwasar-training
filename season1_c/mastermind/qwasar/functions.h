#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

char* commandInput() {
    char* save = (char*)malloc(5*sizeof(char));
    save[5] = '\0';
    fflush(stdout);
    read(0, save, 5);
    return save;
}

int my_strlen(char* param_1) {
    int length = 0;
    while (*param_1 != '\0') {
        length ++;
        param_1 ++;
    }
    return length;
}

int equality(char* param1, char* param2) {
    int flag = 0;
    while (*param1 != '\0' && *param2 != '\0') {
        if (*param1 != *param2) {
            flag = 1;
            break;
        }
        param1 ++;
        param2 ++;
    }
    
    if (flag == 0) {
        return 0;
    } else {
        return 1;
    }
}

int random_num() {
    int num = rand() % 8;
    char val = num + '0';
    return val;
}

int my_isdigit(char* param_1) {
    int i = 0;
    while (param_1[i] != '\0'){
        if (isdigit(param_1[i])) {
            return 0;
        }
        i++;
    }
    
    return 1;
}

void endfile() {
    return;
}
// int my_isdigit(char* param_1) {
//     int count = 0;
//     for(int i=0; i<strlen(param_1); i++) {
//         if (isdigit(param_1[i])) {
//             return 0;
//         }
//     }
//     return 1;
// }
