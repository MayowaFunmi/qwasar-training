#include <stdio.h>


struct rectangle {
	int length;
	int width;
};

int main() {
	struct rectangle myRectangle;
	myRectangle.length = 5;
	myRectangle.width = 28;
	
	printf("my rectangle has dimensions %d by %d\n", myRectangle.length, myRectangle.width);
	
	// another way
	struct rectangle yourRectangle = {15, 9};
	
	printf("your rectangle has dimensions %d by %d\n", yourRectangle.length, yourRectangle.width);
}
