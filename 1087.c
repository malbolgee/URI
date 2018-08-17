/*
  @autor: Malbolge;
  @data: 16/08/2018;
  @nome: Dama;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()
{

  unsigned short x1, y1, x2, y2;

  while (true)
  {

    scanf("%hd %hd %hd %hd", &x1, &y1, &x2, &y2);

    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
      break;

    if (x1 == x2 && y1 == y2)
      printf("0\n");
    else if (abs(x2 - x1) == abs(y2 - y1))
      printf("1\n");
    else if (x1 == x2 || y1 == y2)
      printf("1\n");
    else
      printf("2\n");

  }
}
