#include <stdio.h>
struct person
{
   int age;
   float weight;
};

int main()
{
    struct person *personPtr, person1, *p2,person2;
    personPtr = &person1;   

    printf("Enter person1 age: ");
    scanf("%d", &personPtr->age);

    printf("Enter person1 weight: ");
    scanf("%f", &personPtr->weight);

    printf("Displaying:\n");
    printf("Age: %d\n", (*personPtr).age); // or use personPtr->weight
    printf("weight: %f\n", personPtr->weight);

    //person2 = {45, 8.44};
    person2.age = 87;
    person2.weight = 23.66;
    p2 = &person2;
    printf("for person 2, age = %d\n", person2.age);
    printf("for person 2, weight = %f kg\n", p2->weight); // (*p2).weight
    return 0;
}

/*
personPtr->age is equivalent to (*personPtr).age

personPtr->weight is equivalent to (*personPtr).weight

int x = 6;
	int *p = &x;
	printf("x has value %d and its address in memory &x is %x\n", x, &x);
	printf("&x and var p are essentially the same, i.e p = &x = %x\n", p);
	// p and &p both give the address of x
	printf("to get the value of x from its pointer, use *p, i.e *p = %d\n", *p);
*/
