/*
  @autor: Malbolge;
  @data: 30/07/2018;
  @nome: Preenchimento de Vetor II;

*/

#include <stdio.h>

int main ()
{

  int n, i, x[1000], k;

  scanf("%d", &n);

  k = 0;

  for (i = 0; i < 1000; i++)
  {

    x[i] = k;
    k++;

    if (k == n)
    {

      k = 0;

    }
  }
  for (i = 0; i < 1000; i++)
  {

    printf("N[%d] = %d\n", i, x[i]);

  }
}
