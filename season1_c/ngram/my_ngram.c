#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
int main(int argc, char* argv[]) { 
    char* string; 
    string = (char*)malloc(100*sizeof(char)); 
    //string = argv[1];
    int others[200];
    int count[200];
 	int capital[200];
    //(void)argc; 
    printf("no of args = %d\n", argc);
    // initialize the frequency of each character to 0 
    for (int i=0; i<200; i++) { 
        count[i] = 0;
    	capital[i] = 0;
 		others[i] = 0;
    }
    // find the total number of occurences of each character 
    for (int a=1; a<argc; a++) { 
        string = argv[a]; 
        for (int x=0; string[x] != '\0'; x++) { 
            if(string[x] >= 97 && string[x] <= 122) {
                count[string[x] - 97] ++; 
                //printf("count = %d", count);
            }
            if(string[x]>=65 && string[x]<=90){ 
                capital[string[x] - 65]++; 
                //printf("capital = %d", capital);
            }
            if(string[x] == ' '){ 
                others[32]++; 
            }
            if(string[x] == ','){ 
                others[44]++; 
            }
            if(string[x] == '.'){ 
                others[46]++; 
            }
        }
    }
      
  	//printf("small = %s\n", *count);
  	//printf("capital = %d\n", *capital);
    // print the frequency of all characters 
 	for (int d=0; d<200; d++) {
 		if(others[d] != 0) {
            printf("%c: %d\n", d, others[d]); 
 		}
    }
 	for (int j=0; j<200; j++) {
 		if(capital[j] != 0) {
            printf("%c: %d\n", (j + 65), capital[j]); 
 		}
    }
    for (int k=0; k<200; k++) { 
        if (count[k] != 0) {
            printf("%c: %d\n", (k + 97), count[k]); 
        }
    }
    return 0; 
 }



/*
    "./my_ngram \"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc malesuada porttitor est, at tempus felis euismod ut. Maecenas luctus nulla id risus porttitor porttitor. Vestibulum blandit sapien sed sodales lobortis. Suspendisse efficitur quam quis risus semper, a blandit elit suscipit. Quisque cursus et risus sit amet facilisis. Curabitur massa tellus, pretium quis accumsan ut, pulvinar a massa. Proin eu iaculis augue. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean sodales metus est, in ullamcorper enim ultricies sed. Phasellus sed sodales orci. Vestibulum a turpis finibus, malesuada arcu eu, volutpat ipsum. Donec sed est dolor. In in lectus eleifend dolor posuere malesuada.\"  \"\"  \"\"  \"\""

    expected:
    " :101\n,:9\n.:14\nA:1\nC:1\nD:1\nI:1\nL:2\nM:1\nN:1\nP:2\nQ:1\nS:1\nV:2\na:44\nb:7\nc:22\nd:22\ne:59\nf:6\ng:3\nh:1\ni:57\nl:35\nm:24\nn:23\no:30\np:19\nq:4\nr:33\ns:69\nt:47\nu:54\nv:2\n"

    got:
    "a:44\nb:7\nc:22\nd:22\ne:59\nf:6\ng:3\nh:1\ni:57\nl:35\nm:24\nn:23\no:30\np:19\nq:4\nr:33\ns:69\nt:47\nu:54\nv:2\n"

    expected: " :101\n,:9\n.:14\nA:1\nC:1\nD:1\nI:1\nL:2\nM:1\nN:1\nP:2\nQ:1\nS:1\nV:2\na:44\nb:7\nc:22\nd:22\ne:59\nf:6\ng:3\nh:1\ni:57\nl:35\nm:24\nn:23\no:30\np:19\nq:4\nr:33\ns:69\nt:47\nu:54\nv:2\n"                                                                                                                               
    got: "a:45\nb:7\nc:23\nd:23\ne:59\nf:6\ng:3\nh:1\ni:58\nl:37\nm:25\nn:24\no:30\np:21\nq:5\nr:33\ns:70\nt:47\nu:54\nv:4\n"
*/