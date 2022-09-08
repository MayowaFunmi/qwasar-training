#include <stdio.h> 
#include <string.h>

void deleteduplicate(char *s,char c)
{
	int i,k=0;
 
    
    for(i=0;s[i];i++)
    {
     	s[i]=s[i+k];

     	
     	if(s[i]==c)
     	{
		  k++;
		  i--;
	    }
    
    }

	   
	   
  	 
}


char findduplicate(char *s)
{
	char c='*';
	int i,j;
 
    
    for(i=0;s[i];i++)
    {
    	if(!(s[i]==c))
    	{
    		for(j=i+1;s[j];j++)
            {
            	if(s[i]==s[j])
            	   s[j]=c;
        	
		    }
    		
		}
     	
     	
    }
	   
	return c;
	   
  	 
}


int main()
{

    char s[1000],c;
  
    printf("Enter  the string : ");
    gets(s);
      
    c=findduplicate(s);
    deleteduplicate(s,c);
    printf("string after removing all duplicates:");

    printf("%s",s);

	return 0;
 
     
     
}