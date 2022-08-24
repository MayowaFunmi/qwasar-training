#include <stdio.h>


typedef struct{
	int length;
	int width;
} rectangle;

typedef struct{
	int x;
	int y;
} position;

typedef struct{
	char name[30];
	rectangle myRectangle;
	position myPosition;
} buildingPlan;


int main() {
	// no need to start with struct keyword
	rectangle myRectangle;
	myRectangle.length = 5;
	myRectangle.width = 28;
	
	printf("my rectangle has dimensions %d by %d\n", myRectangle.length, myRectangle.width);
	
	// another way
	rectangle yourRectangle = {15, 9};
	
	printf("your rectangle has dimensions %d by %d\n", yourRectangle.length, yourRectangle.width);
	
	// building plan section
	buildingPlan myHouse = {"Akinade Mayowa", {5, 13}, {4, 9}};
	printf("For %s 's rectangle, length is %d, width is %d, and x-coord is %d and y-coord is %d\n", myHouse.name, myHouse.myRectangle.length, myHouse.myRectangle.width, myHouse.myPosition.x, myHouse.myPosition.y);
	
	// arrays on position struct
	position path[] = {{0, 6}, {5, 3}, {1, 9}};
	for (int i=0; i < 3; i++) {
		printf("%d %d\n", path[i].x, path[i].y);
	}
	
	// pointers
	buildingPlan *structPointer = &myHouse;
	printf("name is %s\n", structPointer -> name);
	
	printf("dimension of rectangle is %d cm by %d cm\n", structPointer -> myRectangle.length, structPointer -> myRectangle.width);
	
	printf("position of rectangle is %d by %d\n", structPointer -> myPosition.x, structPointer -> myPosition.y);
	
	return 0;
}
