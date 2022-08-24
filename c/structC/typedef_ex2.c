#include <stdio.h>
#include <string.h>

// struct with typedef person
typedef struct {
  char name[50];
  int citNo;
  float salary;
} person;

int main() {

  // create  Person variables
  person p1, p2;

  // assign value to name of p1
  strcpy(p1.name, "George Orwell");

  // assign values to other p1 variables
  p1.citNo = 1984;
  p1. salary = 2500;

  // print struct variables
  printf("Name: %s\n", p1.name);
  printf("Citizenship No.: %d\n", p1.citNo);
  printf("Salary: %.2f\n", p1.salary);
  
  
  // assign value to name of p2
  strcpy(p2.name, "Akinade Mayowa");

  // assign values to other p2 variables
  p2.citNo = 1987;
  p2.salary = 53700;

  // print struct variables
  printf("Name: %s\n", p2.name);
  printf("Citizenship No.: %d\n", p2.citNo);
  printf("Salary: %.2f", p2.salary);
  return 0;
}
