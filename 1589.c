/*
  @autor: Malbolge;
  @data: 02/08/2018;
  @nome: Bob Conduite;
*/

#include <stdio.h>

int main ()
{

  int n, R1, R2, resultado = 0;

  scanf("%d", &n);

  for (unsigned int i = 0; i < n; i++)
  {

    scanf("%d %d", &R1, &R2);
    printf("%d\n", R1 + R2);

  }

}
