#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_spaceship(char* param_1){
    // let r = right; left = l, etc
    //char buffer[];
    int x_coord = 0;
    int y_coord = 0;
    char cur_pos = 'u';
    char* direction;
    direction = (char*)malloc(strlen(param_1)*sizeof(char));
    //printf("%d\n", size);
    char* result;
    result = (char*)malloc(500*sizeof(char));

    direction = "up";
    //int size = sizeof(param_1)/sizeof(param_1[0]);
    for (int i=0; i<strlen(param_1); i++) {
        if(param_1[i] == 'R') {
            if (cur_pos == 'u') {
                direction = "right";
                cur_pos = 'r';
            } else if (cur_pos == 'l') {
                direction = "up";
                cur_pos = 'u';
            } else if (cur_pos == 'd') {
                direction = "left";
                cur_pos = 'l';
            } else {
                direction = "down";
                cur_pos = 'd';
            }
        } else if (param_1[i] == 'L') {
            if (cur_pos == 'u') {
                direction = "left";
                cur_pos = 'l';
            } else if (cur_pos == 'l') {
                direction = "down";
                cur_pos = 'd';
            } else if (cur_pos == 'd') {
                direction = "right";
                cur_pos = 'r';
            } else {
                direction = "up";
                cur_pos = 'u';
            }
        } else if (param_1[i] == 'A') {
            if (cur_pos == 'u') {
                y_coord --;
            } else if (cur_pos == 'l') {
                x_coord --;
            } else if (cur_pos == 'd') {
                y_coord ++;
            } else if (cur_pos == 'r'){
                x_coord ++;
            }
        }
    }
    snprintf(result, 100, "{x: %d, y: %d, direction: '%s'}", x_coord, y_coord, direction);
    free(result);
    printf("{x: %d, y: %d, direction: '%s'}", x_coord, y_coord, direction);
    printf("%s\n", result);
    return result;
    // printf("%c\n", cur_pos);
    // printf("%s\n", direction);
    // printf("{x: %d, y: %d, direction: %s}", x_coord, y_coord, direction);
    //return `{x: ${x_coord}, y: ${y_coord}, direction: '${cur_pos}'}`
}

char main() {
    char* dir; // = "RAJ";
    dir = "RAALALL"; //RAALALL
    printf("%s\n", my_spaceship(dir));
}