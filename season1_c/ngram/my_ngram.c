#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* string;
    string = (char*)malloc(100*sizeof(char));
    //string = argv[1];
    int count[500];
    int capital[500];
    char special[500];
    //(void)argc;

    // initialize the frequency of each character to 0
    for (int i=0; i<50; i++) {
        count[i] = 0;
        capital[i] = 0;
        special[i] = 0;
    }

    // find the total number of occurences of each character
    for (int a=1; a<argc; a++) {
        string = argv[a];
        for (int x=0; string[x] != '\0'; x++) {
            if(string[x] >= 'a' && string[x] <= 'z') {
                count[string[x] - 97] ++;
            }
            if(string[x]>='A' && string[x]<='Z'){
                capital[string[x] - 65]++;
            }
            if(string[x]>=' '){
                count[string[x] - 65]++;
            }
        }
    }
    

    // print the frequency of all characters
    for (int j=0; j<50; j++) {
        if (capital[j] != 0) {
            printf("%c: %d\n", (j + 65), capital[j]);
        }
    }
    for (int i=0; i<50; i++) {
        if (count[i] != 0) {
            printf("%c: %d\n", (i + 65), count[i]);
        }
    }
    for (int j=0; j<50; j++) {
        if (special[j] != 0) {
            printf("%c: %d\n", (j + 65), special[j]);
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