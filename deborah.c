#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
  char* string;
  string = (char*)malloc(100*sizeof(char));
  int numbers[200];
  int pages[200];
  int last[200];
  printf("no of args = %d/n", argc);
  for(int i = 0; i < 200; i++) {
    pages[i] = 0;
    last[i] = 0;
    numbers[i] = 0;
    
  }
  for (int a=1; a<argc; a++) {
    string = argv[a];
    for (int v = 0; string[v]!='\0'; v++) {
    if(string[v] >= 97 && string[v] <= 122){
      pages[string[v] - 97]++;
    }
    if(string[v]>=65 && string[v]<=90){
      last[string[v]-65]++;
    }
    if(string[v] == ' '){
      numbers[32]++;
    }
    if(string[v] ==','){
      numbers[44]++;
    }
    if(string[v] =='.'){
      numbers[46]++;
    }
    }
  }
for (int y = 0; y < 200; y++) {
  if(numbers[y] != 0) {
    printf("%c:%d\n",y,numbers[y]);
  }
}
for (int j = 0; j < 200; j++) {
  if(last[j] != 0) {
    printf("%c: %d\n", (j + 65), 
      last[j]);
  }
}
for(int e = 0; e < 200; e++) {
  if (pages[e] != 0){
    printf("%c: %d\n",(e + 97),
      pages[e]);
  }
}
return 0;
}