/*
  @autor: Malbolge;
  @data: 30/07/2018;
  @nome: Linha na Matriz;
*/

#include <stdio.h>

int main ()
{

  float m[12][12], soma = 0, media = 0, elemento;
  int i, j, linha;
  char operacao;

  scanf("%d %c", &linha, &operacao);

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
    i = linha;
    while (i == linha)
    {

      for (j = 0; j < 12; j++)
      {

        soma += m[i][j];

      }

      i++;

    }

    printf("%.1f\n", soma);

  }
  else
  {

    if (operacao == 'M')
    {
      i = linha;
      while (i == linha)
      {

        for (j = 0; j < 12; j++)
        {

          media += m[i][j];

        }

        i++;

      }

      printf("%.1f\n", media/12);

    }
  }
}
