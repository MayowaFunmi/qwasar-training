#include <string.h>
#include <stdio.h>

int main() {
    char* sent = "aaaaddabbbcdca";
    //char* alph_store = malloc(100);
    
    for (int i=0; i<strlen(sent); i++) {
        int count = 1;
        if (sent[i]) {
            if (sent[i] != '\0') {
                for (int j=i+1; j<strlen(sent); j++) {
                    if (sent[i] == sent[j]) {
                        count ++;
                        sent[j] = '\0';
                    }
                }
	    	    printf(" '%c' = %d \n",sent[i],count);
            }
        }
        
    }
}