/* C program to Print Square Pattern */
#include<stdio.h>

int main()
{
    int i, j, Side;
    char Ch;

    printf("Please Enter any Symbol\n");
    scanf("%c", &Ch);

    printf("Please Enter Any Side of a Square\n");
    scanf("%d", &Side);

    for(i = 0; i < Side; i++)
    {
        for(j = 0; j < Side; j++)
        {
           printf("%c", Ch);
        }
        
        printf("\n");
    }
    
    return 0;
}
