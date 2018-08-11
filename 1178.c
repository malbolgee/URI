/*
  @autor: Malbolge;
  @data: 30/07/2018;
  @nome: Preenchimento de Vetor III;
*/

#include <stdio.h>

int main ()
{
  int i;
  double x[100];
  double n;

  scanf("%lf", &n);
  x[0] = n;
  for (i = 1; i < 100; i++)
  {
    n = n/2;
    x[i] = n;

  }
  for (i = 0; i < 100; i++)
  {

    printf("N[%d] = %.4lf\n", i, x[i]);

  }
}
