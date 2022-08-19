#include <stdio.h>

// returns true if `X` and `Y` are the same
int compare(const char *X, const char *Y)
{
	while (*X && *Y)
	{
		// printf("X = %c\n", *X);
		// printf("Y = %c\n", *Y);
		if (*X != *Y) {
			return 0;
		}

		X++;
		Y++;
	}

	return (*Y == '\0');
}

// Function to implement `strstr()` function
const char* strstr(const char* X, const char* Y)
{
	while (*X != '\0')
	{
		if ((*X == *Y) && compare(X, Y)) {
			printf("%s\n", X);
			return X;
		}
		X++;
	}

	return NULL;
}

// Implement `strstr()` function in C
int main()
{
	char *X = "scholar";
	char *Y = "ol";

	printf("%s\n", strstr(X, Y));

	return 0;
}