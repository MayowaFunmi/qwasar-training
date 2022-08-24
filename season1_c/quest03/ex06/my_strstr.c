#include <stdio.h>
#include <string.h>

int is_equal(char* param_1, char* param_2) {
    // if param_1 and param_2 are equal, return true
    while (*param_1 && *param_2){
        if (*param_1 != *param_2) {
            return 0;
        }
        param_1 ++;
        param_2 ++;
    }
    return (*param_2 == '\0');
}

char* my_strstr(char* param_1, char* param_2){
    if (strlen(param_2) == '\0') {
        return param_1;
    }
    while (*param_1 != '\0') {
        if ((*param_1 == *param_2) && is_equal(param_1, param_2)) {
            return param_1;
        }
        param_1 ++;
    }
    return NULL;
}  

// Implement `strstr()` function in C
int main()
{
	char *X = "scholar";
	char *Y = "ol";

	printf("%s\n", strstr(X, Y));

	return 0;
}
/*
while letter_s1 in s1
  while letter_s2 in s2
    if letter_s1 != letter_s2
      break
  if reach end of s2
    return &s1[index]
return NULL
*/