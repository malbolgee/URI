/*
  @autor: Malbolge;
  @data: 16/08/2018;
  @nome: Lajotas Exagonais;
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main ()
{

  unsigned short lajotas;

  while (true)
  {
    scanf("%hd", &lajotas);

    if (lajotas == 0)
      break;

    if (lajotas == 1)
      printf("1\n");
    else
    {
      printf("%.0f\n", (1/sqrt(5))*pow(((1+sqrt(5))/2), lajotas+1)-(1/sqrt(5))*pow(((1-sqrt(5))/2), lajotas+1));
    }
  }
}
