#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define NUM_STRINGS 4

int random_num() {
    int num;
    num = rand() % 80+1;
    return (num);
}

int compare(char *a,char *b){  
    int flag=0;  
    while(*a!='\0' && *b!='\0')    
    {  
        if(*a!=*b)  
        {  
            flag=1;
            break;
        }  
        a++;  
        b++;  
    }  
    if(flag==0 && *a=='\0' && *b=='\0')
        return 0;
    if(*a > *b)
        return 1;
    else
        return -1;
 
}

char* capitalize(char* param) {
    for (int i=0; param[i] != '\0'; i++) {
        if (i==0) {
            if ((param[i] >= 'a' && param[i] <= 'z')) {
                param[i] = param[i] - 32;
            }
        }

        // if all inputs are upper case
    }
    return param;
}

char* fetchColor(int x) {
    char* game_color;
    game_color = malloc(10);
    if (x <=10 && x >= 1) {
        game_color = "Red";
    }
    if (x <=20 && x >= 11) {
        game_color = "Green";
    }
    if (x <=30 && x >= 21) {
        game_color = "Blue";
    }
    if (x <=40 && x >= 31) {
        game_color = "Purple";
    }
    if (x <=50 && x >= 41) {
        game_color = "Yellow";
    }
    if (x <=60 && x >= 51) {
        game_color = "White";
    }
    if (x <=70 && x >= 61) {
        game_color = "Orange";
    }
    if (x <=80 && x >= 71) {
        game_color = "Black";
    }
    return game_color;
}



int main() {
    // create the code makers 4 colors
    time_t t1;
    char* temp_color, *color;
    char* colors[NUM_STRINGS] = {"", "", "", ""};   // codemaker's colors
    char* pre_def_colors[8] = {"Red", "Green", "Blue", "Purple", "Yellow", "Black", "White", "Orange"};
    
    color = malloc(10);
    int temp_int;
    srand((unsigned) time(&t1));
    for (int i=0; i<NUM_STRINGS; i++) {
        temp_int = random_num();
        color = fetchColor(temp_int);
        colors[i] = color;
    }
    // display the code maker's colors, hide upon execution
    for (int i = 0; i < NUM_STRINGS; ++i) {
        printf("%s ", colors[i]);
    }
    printf("\n");

    // display the instructions for the game
    printf("......Welcome to the Mastermind game.......\n");

    // users/code breakers choose colors
    int loop = 0;
    char user_color[10];
    char* user_colors[NUM_STRINGS] = {"", "", "", ""};   // code breaker's colors

    while (loop < NUM_STRINGS) {
        printf("Enter color %d: \n", (loop + 1));
        scanf("%s", user_color);
        // capitalize
        char* user = capitalize(user_color);

        // check if user color is present in pre_def_colors
        int y = 0, j=0;
        while(pre_def_colors[y]) {
            // or simply use (strcmp(pre_def_colors[y], user_color) == 0)
            if (compare(pre_def_colors[y], user) != 0) {
                j++;
            }
            y++;
        }
        if (j == 8) {
            printf("Sorry, color %s is not available. Please try again!!\n", user);
            continue;
        }
        user_colors[loop] = user;
        loop ++;
    }
    for (int i=0; i<NUM_STRINGS; i++) {
        printf("user = %s\n", user_colors[i]);
    }
    return 0;
}
