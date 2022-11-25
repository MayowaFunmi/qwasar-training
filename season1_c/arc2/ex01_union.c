#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_concat(char* str1, char* str2){
	int i=0, j=0;
	while(str1[i] != '\0') {
		i++;
	}
	while(str2[j] != '\0') {
		str1[i] = str2[j];
		j++;
		i++;
	}
	//str1[i] = '\0';
	printf("%s\n", str1);
	return str1;
}
 
char* my_union(char* param_1, char* param_2) {	
	//printf("%s\n", my_concat(param_1, param_2));
	return my_concat(param_1, param_2);
}

int main() {
  char* param_1 = "zpadinton";
  char* param_2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
  printf("union = %s\n", my_concat(param_1, param_2));
}
