// C code for hollow rectangle
#include <stdio.h>

// Function to print hollow rectangle
void print_rectangle(int n, int m)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (i==1 || i==n)       //(i==1 || i==n || j==1 || j==m)		
				printf("o");		
			else
				printf(" ");		
		}
		printf("\n");
	}

}

// Driver program for above function
int main()
{
	int rows = 6, columns = 4;
	print_rectangle(rows, columns);
    //printf("%5s\n", "t");
	return 0;
}
