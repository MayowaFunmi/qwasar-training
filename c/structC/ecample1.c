#include <stdio.h>
#include <string.h>

// create struct with person1 variable
struct Person {
  char name[50];
  int citNo;
  float salary;
} person1, person2;

int main() {

  // assign value to name of person1
  strcpy(person1.name, "George Orwell");

  // assign values to other person1 variables
  person1.citNo = 1984;
  person1. salary = 2500;

  // print struct variables
  printf("Name: %s\n", person1.name);
  printf("Citizenship No.: %d\n", person1.citNo);
  printf("Salary: %.2f", person1.salary);
  
  // for person 2
  strcpy(person2.name, "Akinade Mayowa");
  person2.citNo = 58;
  person2.salary = 65.999;
  
  printf("Name: %s\n", person2.name);
  printf("Citizenship No.: %d\n", person2.citNo);
  printf("Salary: %.2f", person2.salary);

  return 0;
}
