/*
  @autor: Malbolge;
  @data: 01/08/2018;
  @nome: Abaixo da Diagonal Secundaria;
*/

#include <stdio.h>

int main ()
{

  float m[12][12], soma = 0, media = 0, cont = 0;
  int i, j;
  char operacao;

  scanf("%c", &operacao);

  for (i = 0; i < 12; i++)
  {

    for (j = 0; j < 12; j++)
    {

        scanf("%f", &m[i][j]);

    }
  }

  if (operacao == 'S')
  {

    for (i = 0; i < 12; i++)
    {
      j = 11;
      while (i != 12 - j - 1)
      {

        soma += m[i][j];
        j--;

      }
    }

    printf("%.1f\n", soma);

  }
  else
  {

    if ( operacao == 'M')
    {

      for (i = 0; i < 12; i++)
      {

        j = 11;
        while (i != 12 - j - 1)
        {

          media += m[i][j];
          j--;
          cont++;

        }
      }

      printf("%.1f\n", media/cont);

    }
  }
}
