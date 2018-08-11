/*
  @autor: Malbolge;
  @data: 02/08/2018;
  @nome: Corrida de Lesmas;
*/

#include <stdio.h>

int main ()
{


  unsigned short int n, maior, velocidade;

  while (scanf("%hd", &n) != EOF)
  {

    int vetor[n];
    for (unsigned i = 0; i < n; i++)
      scanf("%d", &vetor[i]);

    maior = vetor[0];
    for (unsigned i = 1; i < n; i++)
    {

      if (vetor[i] > maior)
        maior = vetor[i];

    }

    if (maior < 10)
      printf("1\n");
    else if ( maior >= 10 && maior < 20)
      printf("2\n");
    else if (maior >= 20)
      printf("3\n");

  }
}
