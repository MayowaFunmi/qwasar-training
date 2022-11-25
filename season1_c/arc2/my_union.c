#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_concat(char* str1, char* str2){
	char* str3;
	int i = 0, j = 0, k=0;
	while (str1[i] != '\0') {
		str3[j] = str1[i];
        i++;
        j++;
    }
    
  while (str2[k] != '\0') {
  	str3[j] = str2[k];
  	k++;
  	j++;
  }
  str3[j] = '\0';
  return str3;
}
 
char* my_union(char* param_1, char* param_2) {
	char new_str[50] = "";
	int k=0;
	for(int i=0;i<strlen(param_2);i++){
		if(!(strchr(param_1, param_2[i]))){
			new_str[k] = param_2[i];
			k++;
		}
	}
	my_concat(param_1, new_str);
	//return new_str;
}

int main() {
  char* param_1 = "zpadinton";
  char* param_2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
  printf("union = %s\n", my_union(param_1, param_2));
}
