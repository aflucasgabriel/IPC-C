#include <stdio.h>
#include <stdlib.h>
int main()
{
  //dobro do valor
  
  int a = 100;
  int *b;
  int **c;
  int ***d;

  b = &a;
  c = &b;
  d = &c;

  printf("valor: %d\n", a);
  printf("dobro: %d\n", (*b *2));
  printf("triplo: %d\n", (**c *3));
  printf("quadruplo: %d\n", (***d *4));
    return 0;
}
