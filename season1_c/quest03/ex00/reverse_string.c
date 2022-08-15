#include<stdio.h>
#include<string.h>

char *reverse_string(char *str)
{
    //start points to start, end points to last and temp is for swapping two characters
    char *start,*end,temp;
    start=str;
    end=str;
    int len=strlen(str);
 
    //pointing end to last character
    for(int i=0;i<len-1;i++)
    end++;
    for(int i=0;i<len/2;i++)
    {
        //Swapping characters at start and end places
        temp=*start;
        *start=*end;
        *end=temp;
 
        //Incrementing start and decrementing end character
        start++;
        end--;
    }
    return str;
}
// int main() 
// {
//     char str[50];
//     printf("Enter String: ");
//     gets(str);
//     char *rev=rev_string(str);
//     printf("Reversed String is: %s",rev);
 
//     return 0;
// }

int main() {
  char my_str[] = "Hello";
  
  printf("Before reverse -> %s\n", my_str);
  printf("Reverse -> %s\n", reverse_string(my_str));
  return 0;
}