#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char argv[] )  {

    char* sent = "aaaabbbcadaad";
    char* alph_store = malloc(100);
 
    //iterate through the string
    for(int i=0; sent[i]!='\0'; i++){

        //take the current character and start iterating from the index

        if(strchr(alph_store, sent[i]) == NULL){

            int counter = 1;
            for(int j=i+1; sent[j] !='\0'; j++){

                if(sent[j]==sent[i]){
                    ++counter;
                }
            }

            // if (strchr(alph_store, sent[i]) == NULL) 
            printf("%c:%d\n", sent[i], counter); 
            alph_store[i] = sent[i];

        }
    }

}