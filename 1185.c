/*
  @autor: Malbolge;
  @data: 31/07/2018;
  @nome: Acima da Diagonal Secundaria;
*/

#include <stdio.h>

int main ()
{

  float m[12][12], soma = 0, media = 0;
  unsigned short int i, j, cont = 0;
  char operacao;

  scanf("%c", &operacao);

  for (i = 0; i < 12; i++)
    for (j = 0; j < 12; j++)
      scanf("%f", &m[i][j]);

  if (operacao == 'S')
  {

    for (i = 0; i < 12; i++)
    {
      j = 0;
      while (i != 12 - j - 1)
      {

        soma += m[i][j];
        j++;

      }
    }

    printf("%.1f\n", soma);

  }
  else
  {

    if (operacao == 'M')
    {

      for (i = 0; i < 12; i++)
      {

        j = 0;
        while (i != 12 - j - 1)
        {

          media += m[i][j];
          j++;
          cont++;

        }
      }

      printf("%.1f\n", media/cont);

    }
  }
}
