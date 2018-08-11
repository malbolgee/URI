/*
  @autor: Malbolge;
  @data: 02/08/2018;
  @nome: A Resposta de Theon;
*/

#include <stdio.h>

int main ()
{

  unsigned short int n, x, menor, posicao = 0;

  scanf("%hd", &n);
  int vetor[n];

  for (unsigned short i = 0; i < n; i++)
      scanf("%d", &vetor[i]);

  menor = vetor[0];

  for (unsigned short i = 0; i < n; i++)
  {

    if (vetor[i] < menor)
    {

      menor = vetor[i];
      posicao = i;

    }
  }

  printf("%d\n", posicao+1);

}
