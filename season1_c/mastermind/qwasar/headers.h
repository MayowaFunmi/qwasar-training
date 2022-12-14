#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#ifndef MASTERMIND_H
#define MASTERMIND_H

void start_info();
char* commandInput();
int my_strlen(char* param_1);
int equality(char* param1, char* param2);
int random_num();
int my_isdigit(char* param_1);
void countUserChar(char* get_code, char* secret);
void checkCode(char* secret);
#endif