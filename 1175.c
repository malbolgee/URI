/*
  @autor: Malbolge;
  @data: 28/07/2018;
  @nome: Troca em Vetor I;
*/

#include <stdio.h>

int main ()
{

  unsigned short i, j;
  short x[20], n, aux1, aux2;

  for (i = 0; i < 20; i++)
  {

    scanf("%hd", &n);
    x[i] = n;

  }

  for (i = 0, j = 19; i <= 10 && j >= 10; i++, j--)
  {

    aux1 = x[i];
    aux2 = x[j];
    x[i] = aux2;
    x[j] = aux1;

  }

  for (i = 0; i < 20; i++)
    printf("N[%d] = %d\n", i, x[i]);

}
