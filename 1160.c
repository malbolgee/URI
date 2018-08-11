/*
  @autor: Malbolge;
  @data: 28/07/2018;
  @nome: Crescimento populacional;
*/

#include <stdio.h>
int main ()
{

  int t, PA, PB, cont = 0, i;
  double G1, G2;

  scanf("%d", &t);

  for (i = 0; i < t; i++)
  {

    scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);

    while (PA <= PB && cont < 101)
    {

      PA += (int)((PA*G1)/100);
      PB += (int)((PB*G2)/100);

      cont++;

    }

    if (cont > 100)
    {
      printf("Mais de 1 seculo.\n");
    }
    else
    {
      printf("%d anos.\n", cont);
    }

    cont = 0;
}
}
