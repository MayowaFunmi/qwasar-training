#include <stdio.h>
#include <string.h>

int main() {
	int x = 6;
	int *p = &x;
	printf("x has value %d and its address in memory &x is %x\n", x, &x);
	printf("&x and var p are essentially the same, i.e p = &x = %x\n", p);
	// p and &p both give the address of x
	printf("to get the value of x from its pointer, use *p, i.e *p = %d\n", *p);
}
