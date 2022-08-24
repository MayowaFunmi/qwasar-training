#include <stdio.h>
#include <string.h>

char* my_spaceship(char* param_1){
    // int size = sizeof(param_1)/sizeof(param_1[0]);
    // for (int i=0; i<size; i++) {
    //     printf("%c", param_1[i]);
    // }
    char cur_pos[] = "up", *ptr_cur;
    char up[] = "up", down[] = "down", right[] = "right", left[] = "left";
    char *ptr_up, *ptr_down, *ptr_right, *ptr_left;
    ptr_up = up;
    ptr_down = down;
    ptr_right = right;
    ptr_left = left;

    ptr_cur = cur_pos;
    int x_coord = 0, y_coord = 0;
    int size = sizeof(param_1)/sizeof(param_1[0]);
    for (int i=0; i < size; i++) {
        char val[1] = "R", *ptr_val;
        ptr_val = val;
        if (param_1[i] == *ptr_val) {
            if (*ptr_cur == *ptr_up) {
                *ptr_cur = *ptr_right;
            }
            //*ptr_val = "right";
            //*ptr_cur = *ptr_val;
            
        }       
    }
    int i = 0;
    while (cur_pos[i] != '\0') {
        printf("%c", cur_pos[i]);
        i++;
    }
    //printf("%c\n", *ptr_cur);

}

void main() {
    char* dir; // = "RAJ";
    dir = "RAV";
    my_spaceship(dir);
}