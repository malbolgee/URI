/*
  @autor: Malbolge;
  @data: 17/08/2018;
  @nome: Soma de Fatoriais;
*/

#include <stdio.h>


int main ()
{

  unsigned short prim_num, seg_num;
  unsigned i;
  long double resultado = 1, resultado2 = 1;

  while (scanf("%hd %hd", &prim_num, &seg_num) != EOF)
  {

    for (i = prim_num; i > 0; i--)
      resultado *= i;
    for (i = seg_num; i > 0; i--)
      resultado2 *= i;

    printf("%.0Lf\n", resultado+resultado2);
    resultado = 1;
    resultado2 = 1;

  }
}
