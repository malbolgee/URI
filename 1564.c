/*
  @autor: Malbolge;
  @data: 02/08/2018;
  @nome: Vai ter Copa?;
*/

#include <stdio.h>

int main ()
{

  unsigned short int n;

  while (scanf("%hd", &n) != EOF)
  {

    if (n == 0)
    {

      printf("vai ter copa!\n");

    }
    else
    {

      printf("vai ter duas!\n");

    }
  }
}
