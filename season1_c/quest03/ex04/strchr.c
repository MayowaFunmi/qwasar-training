#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "abcabc";
  char c[] ="b";
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] = c) {
        printf("new string = %c\n", str[i]);
    }
  }
  return 0;
}