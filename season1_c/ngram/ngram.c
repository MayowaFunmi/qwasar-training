#include <stdio.h>
#include <string.h>
#define MAX 100 // Maximum string size
int main(){
    char string[MAX];
    int i, length;
    int frequency[20];
    /* Input string from user */
    printf("enter the string:\n ");
    gets(string);
    length = strlen(string);
    /* Initialize frequency of each character to 0 */
    for(i=0; i<20; i++){
        frequency[i] = 0;
    }
    /* Find total number of occurrences of each character */
    for(i=0; i<length; i++){
        /* If the current character is lowercase alphabet */
        if(string[i]>='a' && string[i]<='z'){
            frequency[string[i] - 97]++;
        }
        else if(string[i]>='A' && string[i]<='Z'){
            frequency[string[i] - 65]++;
        }
    }
       /* Print the frequency of all characters in the string */
    printf("\nFrequency of all characters in string: \n");
    for(i=0; i<20; i++){
        /* If current character exists in given string */
        if(frequency[i] != 0){
            printf("'%c' = %d\n", (i + 97), frequency[i]);
        }
    }
    return 0;
}