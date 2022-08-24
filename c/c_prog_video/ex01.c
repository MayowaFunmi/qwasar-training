#include <stdio.h>


typedef struct{
	int length;
	int width;
} rectangle;

int main() {
	// no need to start with struct keyword
	rectangle myRectangle;
	myRectangle.length = 5;
	myRectangle.width = 28;
	
	printf("my rectangle has dimensions %d by %d\n", myRectangle.length, myRectangle.width);
	
	// another way
	rectangle yourRectangle = {15, 9};
	
	printf("your rectangle has dimensions %d by %d\n", yourRectangle.length, yourRectangle.width);
}
