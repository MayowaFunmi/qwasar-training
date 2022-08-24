#include <stdio.h>

struct s_coordinate {
  int x;
  int y;
};

int main() {
  struct s_coordinate coord;
  
  coord.x = 0;
  coord.y = 0;
  
  printf("x = %d and y = %d\n", coord.x, coord.y);
  // using pointers on struct
  struct s_coordinate* ptr_on_coord = &coord;
  
  ptr_on_coord->x = 5;
  ptr_on_coord->y = 2;
  printf("using pointers, x = %d and y = %d\n", ptr_on_coord->x, ptr_on_coord->y);
  return 0;
}
