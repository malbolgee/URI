/*
  @autor: Malbolge;
  @data: 31/07/2018;
  @nome: Coluna na Matriz;
*/

#include <stdio.h>

int main ()
{

  float m[12][12], soma = 0, media = 0, elemento;
  int i, j, coluna;
  char operacao;

  scanf("%d %c", &coluna, &operacao);

  for (i = 0; i < 12; i++)
  {

    for (j = 0; j < 12; j++)
    {

      scanf("%f", &elemento);
      m[i][j] = elemento;

    }
  }

  if (operacao == 'S')
  {

    j = coluna;
    while (j == coluna)
    {

      for (i = 0; i < 12; i++)
      {

        soma += m[i][j];

      }

      j++;

    }

    printf("%.1f\n", soma);

  }
  else
  {

    if (operacao == 'M')
    {

      j = coluna;
      while (j == coluna)
      {

        for (i = 0; i < 12; i++)
        {

          media += m[i][j];

        }

        j++;

      }

      printf("%.1f\n", media/12);

    }
  }
}
