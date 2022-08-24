#include <stdio.h>
#include <string.h>

int main() {
	char* haystack = "hello";
	char* needle = "eo";
	char* index[5];
	//char jdex[];
	int x=0;
	int length_haystack = strlen(haystack);
	int length_needle = strlen(needle);
	
	for (int i=0; i < length_haystack; i++){
		for (int j=0; j < length_needle; j++){
			if (haystack[i] == needle[j]) {
				//printf("%d %d\n",i, j);
				for(int x=0;x<strlen(index);x++)
				{
					//printf("%c\n", haystack[i]);
					index[x] = i;
				}
				//printf("%s\n", index); works for letters
				//printf("%d\n", *index);
				//break;	
			}
		}
	}
	//return NULL;
	
	printf("%d\n", *index);
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
